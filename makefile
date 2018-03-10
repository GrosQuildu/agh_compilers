CC = gcc
CFLAGS = -std=c89 -Wall -Werror -pedantic-errors -fstack-protector -D_FORTIFY_SOURCE=2 -Wl,-z,relro -Wl,-z,now -Wformat-security -fsanitize=address,undefined -Werror=array-bounds

SRC = $(wildcard *.c)
EXE = $(SRC:.c=.elf)

all: $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $^

.PHONY: clean
clean:
	rm -f $(EXE)
