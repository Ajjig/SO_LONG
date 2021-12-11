#include "so_long.h"

int	lose_page(t_mlx *mlx)
{
	char	*img;
	int		weight;
	int		height;

	img = mlx_xpm_file_to_image(mlx->mlx, "win.xpm", &weight, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, 0, 0);
	mlx_destroy_image(mlx->mlx, img);
	return (0);
}
