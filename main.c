/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:38 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:24:24 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_mlx *mlx, char type, int x, int y)
{
	int			w;
	int			h;
	char		*img;
	const char	*shur[8] = {"shur/0.xpm", "shur/1.xpm", "shur/2.xpm",
		"shur/3.xpm", "shur/4.xpm", "shur/5.xpm", "shur/6.xpm", "shur/7.xpm"};
	static int	i = 0;

	if (i == 8)
		i = 0;
	if (type == COLL)
		img = "coll.xpm";
	if (type == WALL)
		img = "rock.xpm";
	if (type == EXIT)
		img = "exit.xpm";
	if (type == ENEMY)
	{
		img = mlx_xpm_file_to_image(mlx->mlx, (char *)shur[i++], &w, &h);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
		return ;
	}
	img = mlx_xpm_file_to_image(mlx->mlx, img, &w, &h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
	mlx_destroy_image(mlx->mlx, img);
}

void	between_move(t_mlx *mlx)
{
	char	*img;
	char	*win;

	win = mlx->win;
	img = "move.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, img, &mlx->mi.w, &mlx->mi.h);
	mlx_put_image_to_window(mlx->mlx, win, img, mlx->mi.pos.x, mlx->mi.pos.y);
	mlx_destroy_image(mlx->mlx, img);
}

int	get_next_frame(t_mlx *mlx)
{
	char		*img;
	static int	i = 0;
	static char	*mi[21] = {"m/0.xpm", "m/1.xpm", "m/2.xpm", "m/3.xpm",
		"m/4.xpm", "m/5.xpm", "m/6.xpm", "m/7.xpm", "m/8.xpm", "m/9.xpm",
		"m/10.xpm", "m/11.xpm", "m/12.xpm", "m/13.xpm", "m/14.xpm", "m/15.xpm",
		"m/16.xpm", "m/17.xpm", "m/18.xpm", "m/19.xpm", "m/20.xpm"};

	if (i == 20)
		i = 0;
	enemy_pos(mlx);
	mlx->mi.pos = find_player(mlx->map);
	mlx->mi.pos.x *= ELEMENT_LEN;
	mlx->mi.pos.y *= ELEMENT_LEN;
	img = mlx_xpm_file_to_image(mlx->mlx, "BG.xpm", &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, 0, 0);
	mlx_destroy_image(mlx->mlx, img);
	parse_map(mlx);
	img = mlx_xpm_file_to_image(mlx->mlx, mi[i++], &mlx->mi.w, &mlx->mi.h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->mi.pos.x,
		mlx->mi.pos.y);
	mlx_destroy_image(mlx->mlx, img);
	ft_put_moves(mlx);
	return (0);
}

int	key_read(int key, t_mlx *mlx)
{
	if (key == MOVE_DOWN || key == MOVE_LEFT
		|| key == MOVE_RIGHT || key == MOVE_UP)
		get_player_next_pos(key, mlx, &(mlx->mi.pos));
	if (key == EXIT_KEY)
		kill_game(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_pos		win_len;

	if (ac != 2)
		return (perror(NO_FILE), 1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (perror(NO_BER), 1);
	if (map_checker(av[1], &mlx.map) == 0)
		return (perror(BIG_MAP), 1);
	mlx.moves = 0;
	win_len = get_window_size(mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, win_len.x, win_len.y, NAME);
	mlx_loop_hook(mlx.mlx, &get_next_frame, &mlx);
	mlx_key_hook(mlx.win, &key_read, &mlx);
	mlx_hook(mlx.win, 17, 0, &kill_game, &mlx);
	mlx_loop(mlx.mlx);
}
