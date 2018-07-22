#include "my_header.h"

int transmit(unsigned char *digest, unsigned short the_crc)
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

	struct can_frame frame[3];
	for(i=0; i<2; i++){
		frame[i].can_id  = 0x123;
		frame[i].can_dlc = 8;
		frame[i].data[0] = digest[8*i];
		frame[i].data[1] = digest[8*i+1];
		frame[i].data[2] = digest[8*i+2];
		frame[i].data[3] = digest[8*i+3];
		frame[i].data[4] = digest[8*i+4];
		frame[i].data[5] = digest[8*i+5];
		frame[i].data[6] = digest[8*i+6];
		frame[i].data[7] = digest[8*i+7];
	}
	frame[2].can_id = 0x123;
	frame[2].can_dlc = 6;
	frame[2].data[0] = digest[16];
	frame[2].data[1] = digest[17];
	frame[2].data[2] = digest[18];
	frame[2].data[3] = digest[19];
	frame[2].data[4] = ((unsigned char*)the_crc)[0];
	frame[2].data[5] = ((unsigned char*)the_crc)[1];

	int nbytes;
	for( i=0; i<3; i++ )
		nbytes = write(s, &frame[i], sizeof(struct can_frame));


	for(i=0; i<3; i++ ){
		printf("send to : %d\n data : ", frame[i].can_id);
		for (j = 0; j < frame[i].can_dlc; j++)
			printf("%02X ", frame[i].data[j]);
		printf("\n");
	}
	return 0;
}
