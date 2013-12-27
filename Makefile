TARGET = sample
MIRACLE = libmiracle.a

AR = /usr/bin/ar
#RANLIB = /usr/bin/ranlib
CC = gcc
#CC = gcc-4.2
#CC = clang

CFLAGS = -W -Wall -O3
#CFLAGS = -W -Wall -g
#CFLAGS = -W -Wall -O4

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET):
	cd std/lib; make;
	$(AR) xv *.a; $(AR) r $(MIRACLE) *.o; rm *.o
	$(CC) $(TARGET).c -lmiracle -L./ -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c

clean:
	cd std/lib; make clean;
	rm -rf $(TARGET) $(MIRACLE) *~
