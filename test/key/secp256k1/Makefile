NAME=secp256k1.a
CC=cc
SRC=$(wildcard *.c)
SRC_CRYPTO = $(wildcard crypto/*.c)
SRC_CURVE448 = $(wildcard curve448/*.c)
OBJ=$(SRC:.c=.o) $(SRC_CRYPTO:.c=.o) $(SRC_CURVE448:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: all clean