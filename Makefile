TARGET = libmiracle.a

AR = /usr/bin/ar

all: $(TARGET)

$(TARGET):
	cd std/lib; make;
	$(AR) xv *.a
	$(AR) r $(TARGET) *.o
	rm *.o

clean:
	cd std/lib; make clean;
	rm -rf $(TARGET) *~
