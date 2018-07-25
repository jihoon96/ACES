read.o: read.c
	gcc -c read.c
	
write.o: write.c
	gcc -c write.c

all: read.o write.o
	gcc -o read read.o 
	gcc -o write write.o

clean:
	rm -rf *.o read write
