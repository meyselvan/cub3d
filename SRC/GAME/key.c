#include "../../INC/cub3d.h"

int key_released(int keycode, t_game *game)
{
	if (keycode == 13)
		game->key->w = 0;
	if (keycode == 0)
		game->key->a = 0;
	if (keycode == 1)
		game->key->s = 0;
	if (keycode == 2)
		game->key->d = 0;
	if (keycode == 123)
		game->key->left = 0;
	if (keycode == 124)
		game->key->right = 0;
	return (0);
}
int key_pressed(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	if (keycode == 13)
		game->key->w = 1;
	if (keycode == 0)
		game->key->a = 1;
	if (keycode == 1)
		game->key->s = 1;
	if (keycode == 2)
		game->key->d = 1;
	if (keycode == 123)
		game->key->left = 1;
	if (keycode == 124)
		game->key->right = 1;
	return (0);
}