crc16.o: crc16.c
	gcc -c crc16.c

all: crc16.o
	gcc -o crc16 crc16.o

run: all
	./crc16 test.txt

clean:
	rm -rf crc16 crc16.o
