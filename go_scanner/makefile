CC = gcc
CFLAGS = -std=c89 -g -Wall -Werror -pedantic-errors -fstack-protector -D_FORTIFY_SOURCE=2 -Wl,-z,relro -Wl,-z,now -Wformat-security -fsanitize=address,undefined -Werror=array-bounds
CFLAGS = -std=c89 -g 

TARGET = go2html
SRC = $(wildcard *.c)

all: $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $^

.PHONY: clean
clean:
	rm -f $(TARGET)
