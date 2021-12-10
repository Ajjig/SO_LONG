#include "so_long.h"

int	kill_game(t_mlx *mlx)
{
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->map);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}
