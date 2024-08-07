#include "../../INC/cub3d.h"

int	exit_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void move_player(t_game *game, int direction)
{

	int new_x;
	int new_y;
	(void) new_x;
	(void) new_y;

	new_x = game->loc_px + (int)(cos(game->player->angle) * 10 * direction);
	new_y = game->loc_py + (int)(sin(game->player->angle) * 10 * direction);
}

void player_game(t_game *game)
{
	if (game->key->w)
		move_player(game, 1);
	if (game->key->s)
		move_player(game, -1);
	// if (game->key->d)
	// 	rotate_player(game, 1);
	// if (game->key->a)
	// 	rotate_player(game, -1);
	// if (game->key->right)
	// 	rotate_player(game, 1);
	// if (game->key->left)
	// 	rotate_player(game, -1);
}

int game_hook(void *param)
{
	t_game *game = (t_game *)param;
	(void) game;
	// put_floor_and_ceiling(game);
	
	// player_game(game);
	// casting_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
	return (0);
}