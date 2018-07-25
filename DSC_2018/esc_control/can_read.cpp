#include "my_header.h"
#include <iostream>
#include <pigpio.h>

#define MOTOR_PIN 23
#define STEERING_PIN 18

#define PWM_RANGE 20000
#define PWM_FREQUENCY 40

#define DEFAULT_PWM 1200

int main(int argc, char **argv)
{
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
	unsigned char digest[SHA_DIGEST_LENGTH];
	unsigned short the_crc;

	/* read one frame */
    nbytes= read(s, &frame, sizeof(struct can_frame));
	printf("Recieved bytes : %d\n", nbytes);
	printf("Recieved id : %d\n data : ", frame.can_id);
	for(i = 0; i< frame.can_dlc; i++)
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
	for(i = 0; i< frame.can_dlc; i++)
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
	((unsigned char*)&the_Crc)[0] = frame.data[5];

	/* print received SHA-1 */
	char mdString[SHA_DIGEST_LENGTH*2+1];
	for(i = 0; i < SHA_DIGEST_LENGTH; i++)
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	printf("Recieved SHA-1 : %s\n", mdString);

	/* print received CRC-16 */
	printf("Recieved CRC value is 0x%04X\n", the_crc);

	


	return 0;
}
