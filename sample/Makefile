TARGET = sample

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
	cd ../; make;
	$(CC) $(CFLAGS) $(TARGET).c -lmiracle -L./../ -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c

clean:
	cd ../; make clean;
	rm -rf $(TARGET) $(TARGET).dSYM *~
