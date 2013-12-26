AR = /usr/bin/ar
RANLIB = /usr/bin/ranlib

OBJS = string.o int.o Cstring.o Cint.o
TARGET = libstd.a

include ../../Makefile.in

$(TARGET): $(OBJS) 
	$(AR) -r $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)
	cp $(TARGET) ../../lib/.

clean:
	rm -rf $(OBJS) $(TARGET) *~ ../include/*~ ../../lib/$(TARGET)
