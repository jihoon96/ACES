#include <iostream>
#include <pigpio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

#define MOTOR_PIN 23
#define STEERING_PIN 18

#define PWM_RANGE 20000
#define PWM_FREQUENCY 40

#define DEFAULT_PWM 1200

using namespace std;

const unsigned char hash_cmd[][20] = {
	{0x6c,0xf4,0xcc,0x48,0xc2,0xa7,0xce,0x38,0xd1,0xf8,0xf2,0xb8,0x87,0x3e,0x9b,0xf6,0x9f,0x82,0x66,0x9a},	// Stop       "12001200"
	{0x65,0x21,0x90,0xac,0xb8,0xe3,0x04,0xa9,0xb4,0x02,0xc5,0x2c,0xb6,0xc0,0xdf,0x43,0x85,0xb5,0xcd,0x0f},  // forward    "12001260"
	{0x35,0xc2,0xfe,0x58,0xbb,0x0f,0x6b,0x42,0x4b,0x4c,0x50,0xae,0x8f,0x64,0xe2,0x37,0x58,0x3a,0xe8,0x6b},  // turn right "12601255"
	{0x58,0x02,0x72,0xac,0x43,0xa6,0x67,0xbc,0x5c,0x1d,0x5d,0x4c,0x80,0x1c,0x33,0x02,0x40,0x25,0xa3,0x1c},  // turn left  "11401255"
	{0x65,0x85,0xdb,0x71,0x42,0x3f,0xf0,0x65,0xce,0x89,0x01,0x23,0x93,0x54,0x20,0xfa,0xe5,0xb1,0xd1,0x48}   // backward   "12001150"
}; 

void GPIO_RUN(int i){
	switch(i){
		case 0: //Stop
			gpioPWM(STEERING_PIN, 1200);
			gpioPWM(MOTOR_PIN, 1200);
			break;
		case 1: // forward 
			gpioPWM(STEERING_PIN, 1200);
			gpioPWM(MOTOR_PIN, 1255);
			break;
		case 2: // turn right
			gpioPWM(STEERING_PIN, 1260);
			gpioPWM(MOTOR_PIN, 1255);
			break;
		case 3: // turn left
			gpioPWM(STEERING_PIN, 1140);
			gpioPWM(MOTOR_PIN, 1255);
			break;
		case 4: // backward 
			gpioPWM(STEERING_PIN, 1200);
			gpioPWM(MOTOR_PIN, 1200);
			gpioPWM(STEERING_PIN, 1200);
			gpioPWM(MOTOR_PIN, 1150);
			break;
		default:
			gpioPWM(STEERING_PIN, 1200);
			gpioPWM(MOTOR_PIN, 1200);
			break;
	}
}

int main(int argc, char **argv){
	// init gpio
	gpioInitialise();

	// PWM set range
	gpioSetPWMrange(MOTOR_PIN, PWM_RANGE);
	gpioSetPWMrange(STEERING_PIN, PWM_RANGE);

	// PWM set frequency
	gpioSetPWMfrequency(MOTOR_PIN, PWM_FREQUENCY);
	gpioSetPWMfrequency(STEERING_PIN, PWM_FREQUENCY);

	// init PWM
	gpioPWM(MOTOR_PIN, DEFAULT_PWM);
	gpioPWM(STEERING_PIN, DEFAULT_PWM);

	int s, i, j;
	struct sockaddr_can addr;
	struct ifreq ifr;

	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

	strcpy(ifr.ifr_name, "can0");
	ioctl(s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	bind(s, (struct sockaddr *)&addr, sizeof(addr));

	struct can_frame frame;

	int nbytes;
	unsigned char digest[20];
	clock_t start, end;
	double result = 0;

	for(j=0; j < 100; j++){
		nbytes= read(s, &frame, sizeof(struct can_frame));
		start = clock();
		digest[0] = frame.data[0];
		digest[1] = frame.data[1];
		digest[2] = frame.data[2];
		digest[3] = frame.data[3];
		digest[4] = frame.data[4];
		digest[5] = frame.data[5];
		digest[6] = frame.data[6];
		digest[7] = frame.data[7];		
		end = clock();
		result = result + (double)(end - start);

		nbytes= read(s, &frame, sizeof(struct can_frame));
		start = clock();
		digest[8] = frame.data[0];
		digest[9] = frame.data[1];
		digest[10] = frame.data[2];
		digest[11] = frame.data[3];
		digest[12] = frame.data[4];
		digest[13] = frame.data[5];
		digest[14] = frame.data[6];
		digest[15] = frame.data[7];
		end = clock();
		result = result + (double)(end - start);

		nbytes= read(s, &frame, sizeof(struct can_frame));
		start = clock();
		digest[16] = frame.data[0];
		digest[17] = frame.data[1];
		digest[18] = frame.data[2];
		digest[19] = frame.data[3];	

		for(i = 0; i < 5; i++){
			if(!memcmp(hash_cmd[i], digest, 20)){
				GPIO_RUN(i);
				break;
			}
		}
		end = clock();
		result = result + (double)(end - start);
	}
	result = result*1000/CLOCKS_PER_SEC;
	cout << "Total time : " << result << endl;
}

