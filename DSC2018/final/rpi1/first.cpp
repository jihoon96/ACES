#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <time.h>

using namespace std;

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


	clock_t start, end;
	double result = 0;
	int nbytes;
	struct can_frame frame;
	int steering = 1200;
	int motor = 1200;
	char string[8];
		
	for(i = 0 ; i<20; i++){
		start = clock();

		steering = 1200;
		motor = 1200;
		sprintf(string, "%d%d", steering,motor);

		frame.can_id  = 0x123;
		frame.can_dlc = 8;
		frame.data[0] = string[0]; 
		frame.data[1] = string[1]; 
		frame.data[2] = string[2]; 
		frame.data[3] = string[3]; 
		frame.data[4] = string[4]; 
		frame.data[5] = string[5]; 
		frame.data[6] = string[6]; 
		frame.data[7] = string[7]; 
		nbytes = write(s, &frame, sizeof(struct can_frame));

		end = clock();

		result = result + (double)(end - start);

		printf("send to : %d\n data : ", frame.can_id);
		for (j = 0; j < frame.can_dlc; j++)
			printf("%02X ", frame.data[j]);
		printf("\n");
	}	
	for(i = 0 ; i<20; i++){
		start = clock();

		steering = 1200;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		frame.can_id  = 0x123;
		frame.can_dlc = 8;
		frame.data[0] = string[0]; 
		frame.data[1] = string[1]; 
		frame.data[2] = string[2]; 
		frame.data[3] = string[3]; 
		frame.data[4] = string[4]; 
		frame.data[5] = string[5]; 
		frame.data[6] = string[6]; 
		frame.data[7] = string[7]; 
		nbytes = write(s, &frame, sizeof(struct can_frame));
		end = clock();


		result = result + (double)(end - start);

		printf("send to : %d\n data : ", frame.can_id);
		for (j = 0; j < frame.can_dlc; j++)
			printf("%02X ", frame.data[j]);
		printf("\n");
	}
	for(i = 0 ; i<20; i++){
		start = clock();

		steering = 1260;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		frame.can_id  = 0x123;
		frame.can_dlc = 8;
		frame.data[0] = string[0]; 
		frame.data[1] = string[1]; 
		frame.data[2] = string[2]; 
		frame.data[3] = string[3]; 
		frame.data[4] = string[4]; 
		frame.data[5] = string[5]; 
		frame.data[6] = string[6]; 
		frame.data[7] = string[7]; 

		nbytes = write(s, &frame, sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		printf("send to : %d\n data : ", frame.can_id);
		for (j = 0; j < frame.can_dlc; j++)
			printf("%02X ", frame.data[j]);
		printf("\n");
	}	
	for(i = 0 ; i<20; i++){
		start = clock();

		steering = 1140;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		frame.can_id  = 0x123;
		frame.can_dlc = 8;
		frame.data[0] = string[0]; 
		frame.data[1] = string[1]; 
		frame.data[2] = string[2]; 
		frame.data[3] = string[3]; 
		frame.data[4] = string[4]; 
		frame.data[5] = string[5]; 
		frame.data[6] = string[6]; 
		frame.data[7] = string[7]; 

		nbytes = write(s, &frame, sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		printf("send to : %d\n data : ", frame.can_id);
		for (j = 0; j < frame.can_dlc; j++)
			printf("%02X ", frame.data[j]);
		printf("\n");
	}
	for(i = 0 ; i<20; i++){
		start = clock();

		steering = 1200;
		motor = 1150;
		sprintf(string, "%d%d", steering,motor);

		frame.can_id  = 0x123;
		frame.can_dlc = 8;
		frame.data[0] = string[0]; 
		frame.data[1] = string[1]; 
		frame.data[2] = string[2]; 
		frame.data[3] = string[3]; 
		frame.data[4] = string[4]; 
		frame.data[5] = string[5]; 
		frame.data[6] = string[6]; 
		frame.data[7] = string[7]; 

		nbytes = write(s, &frame, sizeof(struct can_frame));

		end = clock();
		result = result + (double)(end - start);

		printf("send to : %d\n data : ", frame.can_id);
		for (j = 0; j < frame.can_dlc; j++)
			printf("%02X ", frame.data[j]);
		printf("\n");
//		sleep(1);
	}

	result = result*1000/CLOCKS_PER_SEC;

	cout << "Total time : " << result << endl;

	return 0;
}
