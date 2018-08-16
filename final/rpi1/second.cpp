#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <iostream>
#include <openssl/sha.h>
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


	int steering;
	int motor;
	char string[8];
	struct can_frame frame[3];
	int nbytes;
	clock_t start, end;
	double result = 0;

	for(int k = 0; k < 20; k++){
		start = clock();
		steering = 1200;
		motor = 1200;
		sprintf(string, "%d%d", steering,motor);

		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

		for(i=0; i<2; i++){
			frame[i].can_id  = 0x123;
			frame[i].can_dlc = 8;
			for(j=0; j<8; j++){
				frame[i].data[j] = digest[j+i*8];
			}
		}
		frame[2].can_id  = 0x123;
		frame[2].can_dlc = 4;
		frame[2].data[0] = digest[16];
		frame[2].data[1] = digest[17];
		frame[2].data[2] = digest[18];
		frame[2].data[3] = digest[19];

		nbytes = write(s, &(frame[0]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[1]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[2]), sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		for( i=0; i<3; i++){
			printf("send to : %d\n data : ", frame[i].can_id);
			for (j = 0; j < frame[i].can_dlc; j++)
				printf("%02X ", frame[i].data[j]);
			printf("\n");
		}
		sleep(1);
	}
	for(int k = 0; k < 20; k++){
		start = clock();
		steering = 1200;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

		for(i=0; i<2; i++){
			frame[i].can_id  = 0x123;
			frame[i].can_dlc = 8;
			for(j=0; j<8; j++){
				frame[i].data[j] = digest[j+i*8];
			}
		}
		frame[2].can_id  = 0x123;
		frame[2].can_dlc = 4;
		frame[2].data[0] = digest[16];
		frame[2].data[1] = digest[17];
		frame[2].data[2] = digest[18];
		frame[2].data[3] = digest[19];

		nbytes = write(s, &(frame[0]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[1]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[2]), sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		for( i=0; i<3; i++){
			printf("send to : %d\n data : ", frame[i].can_id);
			for (j = 0; j < frame[i].can_dlc; j++)
				printf("%02X ", frame[i].data[j]);
			printf("\n");
		}
		sleep(1);
	}
	for(int k = 0; k < 20; k++){
		start = clock();
		steering = 1260;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

		for(i=0; i<2; i++){
			frame[i].can_id  = 0x123;
			frame[i].can_dlc = 8;
			for(j=0; j<8; j++){
				frame[i].data[j] = digest[j+i*8];
			}
		}
		frame[2].can_id  = 0x123;
		frame[2].can_dlc = 4;
		frame[2].data[0] = digest[16];
		frame[2].data[1] = digest[17];
		frame[2].data[2] = digest[18];
		frame[2].data[3] = digest[19];

		nbytes = write(s, &(frame[0]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[1]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[2]), sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		for( i=0; i<3; i++){
			printf("send to : %d\n data : ", frame[i].can_id);
			for (j = 0; j < frame[i].can_dlc; j++)
				printf("%02X ", frame[i].data[j]);
			printf("\n");
		}
		sleep(1);
	}
	for(int k = 0; k < 20; k++){
		start = clock();
		steering = 1140;
		motor = 1255;
		sprintf(string, "%d%d", steering,motor);

		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

		for(i=0; i<2; i++){
			frame[i].can_id  = 0x123;
			frame[i].can_dlc = 8;
			for(j=0; j<8; j++){
				frame[i].data[j] = digest[j+i*8];
			}
		}
		frame[2].can_id  = 0x123;
		frame[2].can_dlc = 4;
		frame[2].data[0] = digest[16];
		frame[2].data[1] = digest[17];
		frame[2].data[2] = digest[18];
		frame[2].data[3] = digest[19];

		nbytes = write(s, &(frame[0]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[1]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[2]), sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		for( i=0; i<3; i++){
			printf("send to : %d\n data : ", frame[i].can_id);
			for (j = 0; j < frame[i].can_dlc; j++)
				printf("%02X ", frame[i].data[j]);
			printf("\n");
		}
		sleep(1);
	}
	for(int k = 0; k < 20; k++){
		start = clock();
		steering = 1200;
		motor = 1150;
		sprintf(string, "%d%d", steering,motor);

		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

		for(i=0; i<2; i++){
			frame[i].can_id  = 0x123;
			frame[i].can_dlc = 8;
			for(j=0; j<8; j++){
				frame[i].data[j] = digest[j+i*8];
			}
		}
		frame[2].can_id  = 0x123;
		frame[2].can_dlc = 4;
		frame[2].data[0] = digest[16];
		frame[2].data[1] = digest[17];
		frame[2].data[2] = digest[18];
		frame[2].data[3] = digest[19];

		nbytes = write(s, &(frame[0]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[1]), sizeof(struct can_frame));
		nbytes = write(s, &(frame[2]), sizeof(struct can_frame));
		end = clock();

		result = result + (double)(end - start);

		for( i=0; i<3; i++){
			printf("send to : %d\n data : ", frame[i].can_id);
			for (j = 0; j < frame[i].can_dlc; j++)
				printf("%02X ", frame[i].data[j]);
			printf("\n");
		}
		sleep(1);
	}

	result = result*1000/CLOCKS_PER_SEC;

	cout << "Total time : " << result << endl;

	return 0;
}
