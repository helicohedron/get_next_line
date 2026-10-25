NAME = get_next_line.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all