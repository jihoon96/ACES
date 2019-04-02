
SRC_HOME  = ./
APP_HOME  = ../bin

DEFINES    = -DDEBUG1

CFLAGS    = -c ${DEFINES}

OBJS      = main.o
PROG_NAME = iss.exe



all: clean ${PROG_NAME}
	
${PROG_NAME}: ${OBJS}
	g++ -o $@ ${OBJS}
	mv $@ ${APP_HOME}
	rm -rf *.o

.cpp.o:
	g++ ${CFLAGS} $<

clean:
	rm -rf *.o

plot:
	gnuplot -p plot.plt

