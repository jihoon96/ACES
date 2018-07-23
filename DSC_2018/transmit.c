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
		for(j=0; j<8; j++){
			frame[i].data[j] = digest[j+i*8];
		}
	}
	frame[i].can_id  = 0x123;
	frame[i].can_dlc = 6;
	frame[2].data[16] = digest[16];
	frame[2].data[17] = digest[17];
	frame[2].data[18] = digest[18];
	frame[2].data[19] = digest[19];
	frame[2].data[20] = ((unsigned char*)&the_crc)[1];
	frame[2].data[21] = ((unsigned char*)&the_crc)[0];

	int nbytes;
	for( i=0; i<3; i++ )
		nbytes = write(s, &(frame[i]), sizeof(struct can_frame));

	for( i=0; i<3; i++){
		printf("send to : %d\n data : ", frame[i].can_id);
		for (j = 0; j < frame[i].can_dlc; j++)
			printf("%02X ", frame[i].data[j]);
		printf("\n");
	}
	return 0;
}
