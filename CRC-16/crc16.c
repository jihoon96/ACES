#include "crc16.h"

unsigned int crc16(unsigned int crcValue, unsigned char newByte) 
{
	unsigned char i;

	for (i = 0; i < 8; i++) {

		if (((crcValue & 0x8000) >> 8) ^ (newByte & 0x80)){
			crcValue = (crcValue << 1)  ^ POLYNOM;
		}else{
			crcValue = (crcValue << 1);
		}

		newByte <<= 1;
	}
  
	return crcValue;
}

/***** EXAMPLE *****/

unsigned int exampleOfUseCRC16 (unsigned char *Data, usigned char len){

	unsigned int crc;
	unsigned char aux = 0;

	crc = 0x0000; //Initialization of crc to 0x0000 for DNP
	//crc = 0xFFFF; //Initialization of crc to 0xFFFF for CCITT

	while (aux < len){
		crc = crc16(crc,Data[aux]);
		aux++;
	}

	return (~crc); //The crc value for DNP it is obtained by NOT operation

	//return crc; //The crc value for CCITT
}