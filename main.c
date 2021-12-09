/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:38 by majjig            #+#    #+#             */
/*   Updated: 2021/12/09 05:50:06 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item		g_h;
//char		*g_h_img[14] = {"./hero/0.xpm", "./hero/1.xpm", "./hero/2.xpm",
//	"./hero/3.xpm", "./hero/4.xpm", "./hero/5.xpm", "./hero/6.xpm",
//	"./hero/7.xpm", "./hero/8.xpm", "./hero/9.xpm", "./hero/10.xpm",
//	"./hero/11.xpm", "./hero/12.xpm", "./hero/13.xpm"};
char *g_h_img[121] = {"minato/0.xpm", "minato/1.xpm", "minato/2.xpm", "minato/3.xpm", "minato/4.xpm", "minato/5.xpm", "minato/6.xpm", "minato/7.xpm", "minato/8.xpm", "minato/9.xpm", "minato/10.xpm", "minato/11.xpm", "minato/12.xpm", "minato/13.xpm", "minato/14.xpm", "minato/15.xpm", "minato/16.xpm", "minato/17.xpm", "minato/18.xpm", "minato/19.xpm", "minato/20.xpm", "minato/21.xpm", "minato/22.xpm", "minato/23.xpm", "minato/24.xpm", "minato/25.xpm", "minato/26.xpm", "minato/27.xpm", "minato/28.xpm", "minato/29.xpm", "minato/30.xpm", "minato/31.xpm", "minato/32.xpm", "minato/33.xpm", "minato/34.xpm", "minato/35.xpm", "minato/36.xpm", "minato/37.xpm", "minato/38.xpm", "minato/39.xpm", "minato/40.xpm", "minato/41.xpm", "minato/42.xpm", "minato/43.xpm", "minato/44.xpm", "minato/45.xpm", "minato/46.xpm", "minato/47.xpm", "minato/48.xpm", "minato/49.xpm", "minato/50.xpm", "minato/51.xpm", "minato/52.xpm", "minato/53.xpm", "minato/54.xpm", "minato/55.xpm", "minato/56.xpm", "minato/57.xpm", "minato/58.xpm", "minato/59.xpm", "minato/60.xpm", "minato/61.xpm", "minato/62.xpm", "minato/63.xpm", "minato/64.xpm", "minato/65.xpm", "minato/66.xpm", "minato/67.xpm", "minato/68.xpm", "minato/69.xpm", "minato/70.xpm", "minato/71.xpm", "minato/72.xpm", "minato/73.xpm", "minato/74.xpm", "minato/75.xpm", "minato/76.xpm", "minato/77.xpm", "minato/78.xpm", "minato/79.xpm", "minato/80.xpm", "minato/81.xpm", "minato/82.xpm", "minato/83.xpm", "minato/84.xpm", "minato/85.xpm", "minato/86.xpm", "minato/87.xpm", "minato/88.xpm", "minato/89.xpm", "minato/90.xpm", "minato/91.xpm", "minato/92.xpm", "minato/93.xpm", "minato/94.xpm", "minato/95.xpm", "minato/96.xpm", "minato/97.xpm", "minato/98.xpm", "minato/99.xpm", "minato/100.xpm", "minato/101.xpm", "minato/102.xpm", "minato/103.xpm", "minato/104.xpm", "minato/105.xpm", "minato/106.xpm", "minato/107.xpm", "minato/108.xpm", "minato/109.xpm", "minato/110.xpm", "minato/111.xpm", "minato/112.xpm", "minato/113.xpm", "minato/114.xpm", "minato/115.xpm", "minato/116.xpm", "minato/117.xpm", "minato/118.xpm", "minato/119.xpm", "minato/120.xpm"};

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
	img = "./minato/120.xpm";
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
	if (i == 121)
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
	t_pos		win_len;

	if (ac != 2 || map_checker(av[1], &mlx.map) == 0)
		return (-1);
	win_len = get_window_size(mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, win_len.x, win_len.y, NAME);
	mlx_loop_hook(mlx.mlx, &next_frame, &mlx);
	mlx_key_hook(mlx.win, &key_read, &mlx);
	mlx_loop(mlx.mlx);
}
