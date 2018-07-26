#include "my_header.h"

int main()
{
	unsigned char digest[SHA_DIGEST_LENGTH];
	char string[] = "1200";

	SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

	printf("%lu\n", sizeof(digest));

	unsigned short the_crc;

	the_crc = CRCCCITT(digest, sizeof(digest), 0, 0);


	printf("Initial CRC value is 0x%04X\n", the_crc);


	if( transmit(digest, the_crc) != 0){
		printf("transmit error!\n");
		return -1;
	}
	return 0;
}
