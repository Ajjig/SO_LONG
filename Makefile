NAME = so_long.a

EXEC = a.out

MAP = 1337.ber

SRCS =	main.c \
		map_checker.c \
		get_player_next_pos.c \
		find_player.c \
		parse.c \
		libft/ft_strdup.c\
		libft/ft_strlen.c\
		libft/ft_split.c \
		is_possible.c \
		get_win_size.c

MLX = -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	-rm a.out

run: all
	./$(EXEC) $(MAP)

re: fclean make

re-run: fclean run