#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <openssl/sha.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

unsigned short CRCCCITT(unsigned char *data, size_t length, unsigned short seed, unsigned short final);
int transmit(unsigned char *digest, unsigned short the_crc);
