
EXEC = so_long
BEXEC = so_long_bonus

MAP = map.ber

INC = so_long.h
INC_BNS = bonus/so_long.h

SRCS =	main.c \
		map_checker.c \
		get_player_next_pos.c \
		find_player.c \
		parse.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		is_possible.c \
		win_page.c \
		lose_page.c \
		get_win_size.c \
		kill_game.c \
		enemy.c \
		put_moves.c \
		ft_exit.c \
		check_spaces.c

BNS =	bonus/map_checker_bonus.c \
		bonus/get_player_next_pos_bonus.c \
		bonus/find_player_bonus.c \
		bonus/parse_bonus.c \
		bonus/main_bonus.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		bonus/is_possible_bonus.c \
		bonus/win_page_bonus.c \
		bonus/lose_page_bonus.c \
		bonus/get_win_size_bonus.c \
		bonus/kill_game_bonus.c \
		bonus/enemy_bonus.c \
		bonus/put_moves_bonus.c \
		bonus/ft_exit_bonus.c \
		bonus/check_spaces.c

OBJBNS = ${BNS:.c=.o}

MLX = -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(EXEC)

$(EXEC): $(OBJS) $(INC)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS)

clean:
	@rm -rf $(OBJS) $(OBJBNS)

fclean: clean
	@-rm $(EXEC) $(BEXEC)

bonus: $(BEXEC)

$(BEXEC): $(OBJBNS) $(INC_BNS)
	@$(CC) $(CFLAGS) $(MLX) $(OBJBNS) -o $(BEXEC)

run: all
	@./$(EXEC) $(MAP)

re: fclean all

re-run: fclean run
