/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:38 by majjig            #+#    #+#             */
/*   Updated: 2021/12/11 19:20:52 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item		g_h;

char *g_h_img[21] = {"minato/0.xpm", "minato/1.xpm", "minato/2.xpm", "minato/3.xpm", "minato/4.xpm", "minato/5.xpm", "minato/6.xpm", "minato/7.xpm", "minato/8.xpm", "minato/9.xpm", "minato/10.xpm", "minato/11.xpm", "minato/12.xpm", "minato/13.xpm", "minato/14.xpm", "minato/15.xpm", "minato/16.xpm", "minato/17.xpm", "minato/18.xpm", "minato/19.xpm", "minato/20.xpm"};

void	ft_put_img(t_mlx *mlx, char type, int x, int y)
{
	int			weight;
	int			height;
	char		*img;
	char		*shuriken[8] = {"shur/s0.xpm", "shur/s1.xpm", "shur/s2.xpm", "shur/s3.xpm", "shur/s4.xpm", "shur/s5.xpm", "shur/s6.xpm", "shur/s7.xpm"};
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
		img = mlx_xpm_file_to_image(mlx->mlx, shuriken[i++], &weight, &height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
		mlx_destroy_image(mlx->mlx, img);
		return ;
	}
	img = mlx_xpm_file_to_image(mlx->mlx, img, &weight, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
	mlx_destroy_image(mlx->mlx, img);

}

void	between_move(t_mlx *mlx)
{
	char	*img;

	img = "move.xpm";
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
	char		*nb;

	if (i == 20)
		i = 0;
	enemy_pos(mlx);
	g_h.pos = find_player(mlx->map);
	g_h.pos.x *= ELEMENT_LEN;
	g_h.pos.y *= ELEMENT_LEN;
	bg = mlx_xpm_file_to_image(mlx->mlx, "BG.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, bg, 0, 0);
	img = mlx_xpm_file_to_image(mlx->mlx, g_h_img[i++], &g_h.w, &g_h.h);
	parse_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, g_h.pos.x, g_h.pos.y);
	mlx_destroy_image(mlx->mlx, bg);
	mlx_destroy_image(mlx->mlx, img);
	mlx_string_put(mlx->mlx, mlx->win, 10, 5, 0xFFFF00, "KUNSAI USED: ");
	nb = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx, mlx->win, 140, 5, 0xFFFF00, nb);
	return (free(nb), 0);
}

int	key_read(int key, t_mlx *mlx)
{
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
