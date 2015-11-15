TARGET := example

all: $(TARGET)

$(TARGET): main.c
	gcc -o $(TARGET) main.c -lX11

clean:
	rm *.o
	rm $(TARGET)
