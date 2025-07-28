CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic-errors
TARGET = linkedlist

all: $(TARGET)

$(TARGET): $(TARGET).c $(TARGET).h
	$(CC)  $(TARGET).c $(TARGET).h -C test/test.c -o $(TARGET) $(CFLAGS)

clean:
	rm $(TARGET)
