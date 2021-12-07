/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:38 by majjig            #+#    #+#             */
/*   Updated: 2021/12/07 03:18:41 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item		g_h;
char		*g_h_img[14] = {"./hero/0.xpm", "./hero/1.xpm", "./hero/2.xpm",
	"./hero/3.xpm", "./hero/4.xpm", "./hero/5.xpm", "./hero/6.xpm",
	"./hero/7.xpm", "./hero/8.xpm", "./hero/9.xpm", "./hero/10.xpm",
	"./hero/11.xpm", "./hero/12.xpm", "./hero/13.xpm"};
char		*g_coll[9] = {"./coll/0.xpm", "./coll/1.xpm",
	"./coll/2.xpm", "./coll/3.xpm", "./coll/4.xpm",
	"./coll/5.xpm", "./coll/6.xpm", "./coll/7.xpm", "./coll/8.xpm"};

void	ft_put_img(t_mlx *mlx, char type, int x, int y)
{
	int			weight;
	int			height;
	char		*img;
	static int	i = 0;

	if (i == 9)
		i = 0;
	if (type == COLL)
	{
		img = mlx_xpm_file_to_image(mlx->mlx, g_coll[i++], &weight, &height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
	}
}

void	between_move(t_mlx *mlx)
{
	char	*img;

	img = "./hero/13.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, img, &g_h.w, &g_h.h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, g_h.pos.x, g_h.pos.y);
	mlx_destroy_image(mlx->mlx, img);
}

int	next_frame(t_mlx *mlx)
{
	int			img_width;
	int			img_height;
	char		*bg;
	char		*img;
	static int	i = 0;

	bg = "BG.xpm";
	if (i == 14)
		i = 0;
	g_h.pos = find_player(mlx->map);
	g_h.pos.x *= 100;
	g_h.pos.y *= 100;
	bg = mlx_xpm_file_to_image(mlx->mlx, bg, &img_width, &img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, bg, 0, 0);
	img = mlx_xpm_file_to_image(mlx->mlx, g_h_img[i++], &g_h.w, &g_h.h);
	parse_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, g_h.pos.x, g_h.pos.y);
	mlx_destroy_image(mlx->mlx, bg);
	mlx_destroy_image(mlx->mlx, img);
	return (0);
}

int	key_read(int key, t_mlx *mlx)
{
	if (key == MOVE_DOWN || key == MOVE_LEFT
		|| key == MOVE_RIGHT || key == MOVE_UP)
		get_player_next_pos(key, mlx, &(g_h.pos));
	if (key == EXIT_KEY)
	{
		free(mlx->map);
		free(mlx->win);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	char		*bg;
	int			img_width;
	int			img_height;
	t_pos		win_len;

	bg = "BG.xpm";
	if (ac != 2 || map_checker(av[1], &mlx.map) == 0)
		return (-1);
	win_len = get_window_size(mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, win_len.x, win_len.y, NAME);
	bg = mlx_xpm_file_to_image(mlx.mlx, bg, &img_width, &img_height);
	mlx_put_image_to_window(mlx.mlx, mlx.win, bg, 0, 0);
	mlx_loop_hook(mlx.mlx, &next_frame, &mlx);
	mlx_key_hook(mlx.win, &key_read, &mlx);
	mlx_loop(mlx.mlx);
}
