CC=gcc
CFLAGS=-std=gnu11 -Wall -Wextra -g

TARGET_NAME=magic-number

SOURCE_FILES=\
	src/main.c\
	src/magic_numbers.c

INCLUDE_DIRECTORIES=

SYMBOLS=

all: clean default

default: $(TARGET_NAME)

$(TARGET_NAME):
	mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_DIRECTORIES) $(SYMBOLS) $(SOURCE_FILES) -o build/$(TARGET_NAME)

clean:
	rm -rf build
