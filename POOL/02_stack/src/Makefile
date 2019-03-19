SRC_HOME = ./
LIB_HOME = ../../00_lib

INC		=
DEFINES = -DDEBIG

CFLAGS 	= -g $(INC) -c $(DEFINES) -Wno-deprecated -fPIC
LIB		= -lStack # libBaseType.so
LIB_PATH = -L$(LIB_HOME)/bin

OBJS	= main.o
PROG_NAME = stack 
APP_HOME = ../bin

vpath %.cpp $(SRC_HOME)
vpath %.h	$(SRC_HOME)
vpath %.h	$(LIB_HOME)/libStack

all: $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	g++ $(LIB_PATH) -o $@ $(OBJS) $(LIB)
	chmod +x $@
	mv $@ $(APP_HOME)
	cp $(LIB_HOME)/bin/libStack.so $(APP_HOME)
	rm -rf *.o

.cpp.o:
	g++ $(CFLAGS) $<

clean:
	rm -rf *.o
