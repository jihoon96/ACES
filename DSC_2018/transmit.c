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

	struct canfd_frame frame;

	frame.can_id  = 0x123;
	frame.len = 22;
	for(i=0; i<20; i++){
		frame.data[i] = digest[i];
	}
	frame.data[20] = ((unsigned char*)&the_crc)[1];
	frame.data[21] = ((unsigned char*)&the_crc)[0];

	int nbytes;
	for( i=0; i<3; i++ )
		nbytes = write(s, &frame, sizeof(struct canfd_frame));

	printf("send to : %d\n data : ", frame.can_id);
	for (j = 0; j < frame.len; j++)
		printf("%02X ", frame.data[j]);
	printf("\n");

	return 0;
}
