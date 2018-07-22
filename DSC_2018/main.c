#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	unsigned char digest[SHA_DIGEST_LENGTH];
	char string[] = "1200";

	SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

	printf("%d\n", sizeof(digest));

	return 0;
}
