NAME = so_long.a

EXEC = a.out

MAP = 1337.ber

INC = so_long.h

SRCS =	main.c \
		map_checker.c \
		get_player_next_pos.c \
		find_player.c \
		parse.c \
		libft/ft_strdup.c\
		libft/ft_strlen.c\
		libft/ft_split.c \
		libft/ft_itoa.c \
		is_possible.c \
		get_win_size.c \
		kill_game.c

MLX = -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(INC) $(MAP)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@-rm a.out

run: all
	@./$(EXEC) $(MAP)

re: fclean make

re-run: fclean run
