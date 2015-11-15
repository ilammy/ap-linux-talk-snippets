TARGET := read-file

all: $(TARGET)

$(TARGET): main.c
	gcc -std=c99 -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGET)

