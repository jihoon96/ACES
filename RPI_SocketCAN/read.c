#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

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
	for(j = 0 ;j< 10; j++){
       	nbytes= read(s, &frame, sizeof(struct can_frame));
	printf("Recieved bytes : %d\n", nbytes);
	printf("Recieved id : %d\n data : ", frame.can_id);
	for(i = 0; i< frame.can_dlc; i++)
		printf("%02X ", frame.data[i]);
	printf("\n");
	}
	return 0;
}
