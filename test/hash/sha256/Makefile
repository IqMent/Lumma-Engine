G++ = g++
NAME = sha256_test.out
FLAGS = -g
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(G++) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(G++) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

