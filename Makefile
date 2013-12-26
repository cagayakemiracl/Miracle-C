TARGET = sample

$(TARGET):
	cd std/lib; make;
	$(CC) $(TARGET).c -lstd -L./lib -o $(TARGET)

clean:
	cd std/lib; make clean;
	rm -rf $(TARGET) *~
