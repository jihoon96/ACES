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

static unsigned short crc_table [256] = {

0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5,
0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b,
0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210,
0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c,
0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401,
0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b,
0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6,
0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5,
0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969,
0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96,
0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc,
0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03,
0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd,
0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6,
0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a,
0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb,
0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1,
0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2,
0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb,
0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447,
0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8,
0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2,
0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9,
0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827,
0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c,
0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0,
0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d,
0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07,
0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba,
0x8fd9, 0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74,
0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

unsigned short CRCCCITT(unsigned char *data, size_t length, unsigned short seed, unsigned short final)
{ 

   size_t count;
   unsigned int crc = seed;
   unsigned int temp;

   for (count = 0; count < length; ++count)
   {
     temp = (*data++ ^ (crc >> 8)) & 0xff;
     crc = crc_table[temp] ^ (crc << 8);
   }

   return (unsigned short)(crc ^ final);

} 

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
	unsigned char digest[22];
	unsigned short the_crc;

	while(1){
		nbytes= read(s, &frame, sizeof(struct can_frame));
		printf("Recieved bytes : %d\n", nbytes);
		printf("Recieved id : %d\n data : ", frame.can_id);
		for(i = 0; i < frame.can_dlc; i++)
			printf("%02X ", frame.data[i]);
		printf("\n");
		digest[0] = frame.data[0];
		digest[1] = frame.data[1];
		digest[2] = frame.data[2];
		digest[3] = frame.data[3];
		digest[4] = frame.data[4];
		digest[5] = frame.data[5];
		digest[6] = frame.data[6];
		digest[7] = frame.data[7];		

		nbytes= read(s, &frame, sizeof(struct can_frame));
		printf("Recieved bytes : %d\n", nbytes);
		printf("Recieved id : %d\n data : ", frame.can_id);
		for(i = 0; i < frame.can_dlc; i++)
			printf("%02X ", frame.data[i]);
		printf("\n");
		digest[8] = frame.data[0];
		digest[9] = frame.data[1];
		digest[10] = frame.data[2];
		digest[11] = frame.data[3];
		digest[12] = frame.data[4];
		digest[13] = frame.data[5];
		digest[14] = frame.data[6];
		digest[15] = frame.data[7];


		nbytes= read(s, &frame, sizeof(struct can_frame));
		printf("Recieved bytes : %d\n", nbytes);
		printf("Recieved id : %d\n data : ", frame.can_id);
		for(i = 0; i< frame.can_dlc; i++)
			printf("%02X ", frame.data[i]);
		printf("\n");

		digest[16] = frame.data[0];
		digest[17] = frame.data[1];
		digest[18] = frame.data[2];
		digest[19] = frame.data[3];	
		((unsigned char*)&the_crc)[1] = frame.data[4];
		digest[20] = frame.data[4];
		((unsigned char*)&the_crc)[0] = frame.data[5];
		digest[21] = frame.data[5];

		/* print received SHA-1 */
		char mdString[20*2+1];
		for(i = 0; i < 20; i++)
			sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
		printf("Recieved SHA-1 : %s\n", mdString);

		/* print received CRC-16 */
		printf("Recieved CRC value is 0x%04X\n", the_crc);

		unsigned short cal_crc = CRCCCITT(digest, sizeof(digest), 0, 0);

		cout << "cal_crc : " << cal_crc << endl;

		if( cal_crc == 0 ){
			// check SHA-1 command table
			for(i = 0; i < 5; i++){
				if(!memcmp(hash_cmd[i], digest, 20)){
					GPIO_RUN(i);
					break;
				}
			}
		} else{
			// inverse received SHA-1 bits
			for(i = 0; i < 20; i++)
				digest[i] = (unsigned int)digest[i]^0xFF;
			// calculate CRC-16-CCITT again
			cal_crc = CRCCCITT(digest, sizeof(digest), 0, 0);
			cout << "Inversed data cal_crc : " << cal_crc << endl;
			
			if( cal_crc == 0 ){
				// check SHA-1 command table
				for(i = 0; i < 5; i++){
					if(!memcmp(hash_cmd[i], digest, 20)){
						GPIO_RUN(i);
						break;
					}
				}
			}
		}
	}
}

