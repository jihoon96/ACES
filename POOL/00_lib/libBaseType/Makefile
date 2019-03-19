SRC_HOME = ./
LIB_NAME = libBaseType.so
INC		 = 
DEFINES  = -DDEBUG

CFLAGS 	= -g $(INC) -c $(DEFINES) -Wno-deprecated -fPIC
OBJS	= Critical.o

vpath %.cpp $(SRC_HOME)
vpath %.h	$(SRC_HOME)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	g++ -shared -o $@ $(OBJS)
	chmod +x $@
	mv $@ ../bin
	rm -rf *.o

.cpp.o:
	g++ $(CFLAGS) $<

clean:
	rm -rf *.o
