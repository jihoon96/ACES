#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	unsigned char digest[SHA_DIGEST_LENGTH];
	char string[9];
	sprintf(string, "%d%d", 1200,1200);
	printf("%s\n", string);

	SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

	char mdString[SHA_DIGEST_LENGTH*2+1];

	for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

	printf("SHA digest: %s\n", mdString);

	return 0;
}
