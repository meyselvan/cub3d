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
    new_x = game->loc_px + game->player->dir_x * direction;
    new_y = game->loc_py + game->player->dir_y * direction;
    // if (game->map[game->loc_py][new_x] == '0')
        game->loc_px = new_x;
    // if (game->map[new_y][game->loc_px] == '0')
        game->loc_py = new_y;
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

int game_hook(t_game *game)
{
	// put_floor_and_ceiling(game);
	(void)game;
	
	init_raycast(game);
	//player_game(game);
	// casting_rays(game);
	return (0);
}