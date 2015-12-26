NAME = fillit
NAME_TEST = fillit_test
CC = gcc

FLAGS = -Wall
FLAGS += -Wextra
FLAGS += -Werror
FLAGS += -g

LIB = build/libft.a 

SRC += check_valid.c
SRC += checkbuff.c
SRC += fill_buff.c
SRC += main.c
SRC := $(addprefix srcs/, $(SRC))

TEST = lst.c
TEST += main.c
TEST += print.c
TEST += gnl.c
TEST := $(addprefix tests/, $(TEST))

OBJ_SRC = $(SRC:.c=.o)
OBJ_TEST += $(TEST:.c=.o)

GREEN = "\033[1;92m"
NONE = "\033[0m"

.SILENT:

all: $(OBJ_SRC)
	echo "-- Creating $(NAME) ..."
	$(CC) $(FLAGS) $^ $(LIB) -o bin/$(NAME)
	echo $(GREEN)"Done."$(NONE)

%.o:%.c
	@$(CC) $(FLAGS) -I ./includes/ -c $< -o $@

test: $(OBJ_TEST)
	echo "-- Creating  $(NAME_TEST)..."
	$(CC) $(FLAGS) $^ $(LIB) -o bin/$(NAME_TEST)
	echo $(GREEN)"Done."$(NONE)

clean:
	echo "-- Cleaning .o files ..."
	/bin/rm -f $(OBJ_SRC) $(OBJ_TEST)
	echo $(GREEN)"Done."$(NONE)

fclean: clean
	echo "-- Removing binary ..."
	/bin/rm -f $(NAME)
	echo $(GREEN)"Done."$(NONE)

re: fclean all












