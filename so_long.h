#ifndef SO_LONG_H
# define SO_LONG_H

/*		INCLUDES		*/

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

/*		DEFINES		*/

# define MOVE_LEFT 0
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define BUFFER_LEN 1024
# define EXIT 69
# define MOVE_UP 13
# define EXIT_KEY 53
# define ELEMENT_LEN 50
# define PLAYER 80
# define COLL 67
# define EMPTY 48
# define WALL 49
# define SPEED 3
# define NAME "SO_LONG"

/*		ERRORS		*/

# define NO_MAP "Eroor: there is no map given\n"
# define NOT_CLOSED "Error: the map is not closed\n"
# define NO_PLAYER "Error: the map doesnt contain one player\n"
# define NO_COLL "Error: there is no collictible item on the map\n"
# define NO_EXIT "Error: there is no exit item on the map\n"
# define BIG_MAP "Error: the map is too big\n"
# define EMPTY_MAP "\n\n\nMen niytek ????\n\n\n\n"
# define NO_BER "Error: not a '.ber' file"
# define NO_RECTANGLE "Error: the map is not rectangle"
# define NO_FILE "Error there is no valid file given\n"

/*		STRUCTS		*/

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_item
{
	t_pos	pos;
	char	*img;
	int		w;
	int		h;
}				t_item;

typedef struct s_mlx
{
	void	*win;
	void	*mlx;
	char	**map;
	int		count;
	int		moves;
}				t_mlx;

t_pos	find_player(char **map);
char	*ft_itoa(int n);
int		kill_game(t_mlx *mlx);
t_pos	get_window_size(char **map);
void	get_player_next_pos(int key, t_mlx *mlx, t_pos *pos);
int		is_move_up(t_mlx *mlx);
int		is_move_down(t_mlx *mlx);
int		is_move_right(t_mlx *mlx);
int		is_move_left(t_mlx *mlx);
void	move_up(t_mlx *mlx, t_pos *pos);
void	move_down(t_mlx *mlx, t_pos *pos);
void	move_right(t_mlx *mlx, t_pos *pos);
void	move_left(t_mlx *mlx, t_pos *pos);
int		map_checker(char *file, char ***map);
void	between_move(t_mlx *mlx);
int		next_frame(t_mlx *mlx);
void	ft_put_img(t_mlx *mlx, char type, int x, int y);
int		key_read(int key, t_mlx *mlx);
void	parse_map(t_mlx *mlx);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);

#endif
