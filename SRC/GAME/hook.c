#include "../../INC/cub3d.h"

int	exit_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	player_game(t_game *game)
{
	// print_info(game);
	if (game->key->w)
		move_ws(game, 1);
	if (game->key->s)
		move_ws(game, -1);
	if (game->key->a)
		move_ad(game, -1);
	if (game->key->d)
		move_ad(game, 1);
	if (game->key->right)
		rotate_player(game, 1);
	if (game->key->left)
		rotate_player(game, -1);
}

int	game_hook(void *param)
{
	int		x;
	t_game	*game;

	game = (t_game *)param;
	x = 0;
	draw_floor_ceiling(game);
	player_game(game);
	while (x < SCREENWIDTH)
	{
		calc_ray(game, x);
		dda(game);
		calc_wall(game);
		map_line(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
	return (0);
}
