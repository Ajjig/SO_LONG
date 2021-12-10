/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:38 by majjig            #+#    #+#             */
/*   Updated: 2021/12/10 04:28:49 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item		g_h;

char *g_h_img[121] = {"minato/0.xpm", "minato/1.xpm", "minato/2.xpm", "minato/3.xpm", "minato/4.xpm", "minato/5.xpm", "minato/6.xpm", "minato/7.xpm", "minato/8.xpm", "minato/9.xpm", "minato/10.xpm", "minato/11.xpm", "minato/12.xpm", "minato/13.xpm", "minato/14.xpm", "minato/15.xpm", "minato/16.xpm", "minato/17.xpm", "minato/18.xpm", "minato/19.xpm", "minato/20.xpm"};

char		*g_coll[9] = {"./coll/0.xpm", "./coll/1.xpm",
	"./coll/2.xpm", "./coll/3.xpm", "./coll/4.xpm",
	"./coll/5.xpm", "./coll/6.xpm", "./coll/7.xpm", "./coll/8.xpm"};

void	ft_put_img(t_mlx *mlx, char type, int x, int y)
{
	int			weight;
	int			height;
	char		*img;
	static int	i = 0;


	if (type == COLL)
	{
		if (i == 9)
		i = 0;
		img = mlx_xpm_file_to_image(mlx->mlx, g_coll[i++], &weight, &height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
	}
	if (type == WALL)
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "rock.xpm", &weight, &height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
	}
	if (type == EXIT)
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "tree.xpm", &weight, &height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
	}
}

void	between_move(t_mlx *mlx)
{
	char	*img;
	img = "./minato/20.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, img, &g_h.w, &g_h.h);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, g_h.pos.x, g_h.pos.y);
	mlx_destroy_image(mlx->mlx, img);
}

int	get_next_frame(t_mlx *mlx)
{
	int			img_width;
	int			img_height;
	char		*bg;
	char		*img;
	static int	i = 0;

	bg = "BG.xpm";
	if (i == 20)
		i = 0;
	g_h.pos = find_player(mlx->map);
	g_h.pos.x *= ELEMENT_LEN;
	g_h.pos.y *= ELEMENT_LEN;
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
	printf("\n\n%d\n\n", key);
	if (key == MOVE_DOWN || key == MOVE_LEFT
		|| key == MOVE_RIGHT || key == MOVE_UP)
		get_player_next_pos(key, mlx, &(g_h.pos));
	if (key == EXIT_KEY)
		kill_game(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_pos		win_len;

	if (ac != 2 || map_checker(av[1], &mlx.map) == 0)
		return (-1);
	win_len = get_window_size(mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, win_len.x, win_len.y, NAME);
	mlx_loop_hook(mlx.mlx, &get_next_frame, &mlx);
	mlx_key_hook(mlx.win, &key_read, &mlx);
	mlx_hook(mlx.mlx, 17, (1L<<17), &kill_game, &mlx);
	mlx_loop(mlx.mlx);
}
