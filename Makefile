NAME = fillit
CC = clang

FLAGS = -Wall
FLAGS += -Wextra
FLAGS += -Werror

LIB = build/libft.a 

SRC = gnl.c
SRC := $(addprefix srcs/, $(SRC))

TEST = lst.c
TEST += main.c
TEST += print.c
TEST := $(addprefix tests/, $(TEST))

OBJ = $(SRC:.c=.o)
OBJ += $(TEST:.c=.o)

GREEN = "\033[1;92m"
NONE = "\033[0m"

.SILENT:

all: $(OBJ)
	echo "-- Creating $(NAME) ..."
	$(CC) $(FLAGS) $^ $(LIB) -o bin/$(NAME)
	echo $(GREEN)"Done."$(NONE)

%.o:%.c
	@$(CC) $(FLAGS) -I ./includes/ -c $< -o $@

clean:
	echo "-- Cleaning .o files ..."
	/bin/rm -f $(OBJ)
	echo $(GREEN)"Done."$(NONE)

fclean: clean
	echo "-- Removing binary ..."
	/bin/rm -f $(NAME)
	echo $(GREEN)"Done."$(NONE)

re: fclean all












