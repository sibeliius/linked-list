CC = gcc
CFLAGS = -g -march=native -O2 -std=c99 -Wall -Wextra -Wformat=2 -pedantic-errors 
#-g -Wall -std=c99 -pedantic-errors
TARGET = linkedlist

all: $(TARGET)

$(TARGET): $(TARGET).c $(TARGET).h
	$(CC)  $(TARGET).c $(TARGET).h -C test/test.c -o $(TARGET) $(CFLAGS)

asm: $(TARGET).c
	$(CC) -S -fverbose-asm -Wa,-adhln $(CFLAGS) $(TARGET).c -o linkedlist.s

clean:
	rm -f $(TARGET) $(TARGET).s
