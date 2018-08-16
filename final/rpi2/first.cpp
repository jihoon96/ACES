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
	char string[8];
	clock_t start, end;
	double result = 0;
	for(j = 0; j < 10; j++){
		start = clock();
		nbytes= read(s, &frame, sizeof(struct can_frame));
		end = clock();
//		start = clock();
		string[0] = frame.data[0];
		string[1] = frame.data[1];
		string[2] = frame.data[2];
		string[3] = frame.data[3];
		string[4] = frame.data[4];
		string[5] = frame.data[5];
		string[6] = frame.data[6];
		string[7] = frame.data[7];		

		if(strcmp(string, "12001200")){
			GPIO_RUN(0);
		}else if(strcmp(string, "12001255")){
			GPIO_RUN(1);
		}else if(strcmp(string, "12601255")){
			GPIO_RUN(2);
		}else if(strcmp(string, "11401255")){
			GPIO_RUN(3);
		}else if(strcmp(string, "12001150")){
			GPIO_RUN(4);
		}else{
			GPIO_RUN(0);
		}
//		end = clock();
		result = result + (double)(end - start);
	}
	result = result*1000/CLOCKS_PER_SEC;

	cout << "Totoal time : " << result << endl;
	return 0;
}

