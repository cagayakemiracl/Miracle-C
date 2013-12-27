TARGET = libmiracle.a

AR = /usr/bin/ar
CC = gcc
#CC = gcc-4.2
#CC = clang

#CFLAGS = -W -Wall -O3
CFLAGS = -W -Wall -g
#CFLAGS = -W -Wall -O4

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET):
	cd std/lib; make;
	$(AR) xv *.a
	$(AR) r $(TARGET) *.o
	rm *.o

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c

clean:
	cd std/lib; make clean;
	rm -rf $(TARGET) *~
