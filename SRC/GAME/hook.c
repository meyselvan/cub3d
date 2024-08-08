#include "../../INC/cub3d.h"

int	exit_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void move_ws(t_game *game, int direction)
{
	int new_y;

	char c;
	(void) c;

	new_y = game->loc_py + 1 * direction;

	if (game->loc_py >= 0)
		c = 'f';
	else
		c = 'c';

	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2 + game->loc_px] = calc_color(game, c); // eski konumu boyama (bunu yorum satırına alıp daha net anlayabilirsiniz hareketi)
	game->loc_py = new_y;
	printf("game->loc_px: %d\n", game->loc_px);
	printf("game->loc_py: %d\n", game->loc_py);
	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2 + game->loc_px] = 16777215; // beyaz noktanın ilerlemesi

}

void move_ad(t_game *game, int direction)
{
	int new_x;
	char c;
	(void) c;

	new_x = game->loc_px + 1 * direction;

	if (game->loc_py >= 0)
		c = 'f';
	else
		c = 'c';

	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2 + game->loc_px] = calc_color(game, c); // eski konumu boyama (bunu yorum satırına alıp daha net anlayabilirsiniz hareketi)
	game->loc_px = new_x;
	printf("game->loc_px: %d\n", game->loc_px);
	printf("game->loc_py: %d\n", game->loc_py);
	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2 + game->loc_px] = 16777215; // beyaz noktanın ilerlemesi

}


// void move_player(t_game *game, int direction)
// {

// 	int new_x;
// 	int new_y;
// 	(void) new_x;
// 	(void) new_y;

	
// 	// printf("game->player->angle: %f\n", game->player->angle);
// 	// new_x = game->loc_px + (int)(cos(game->player->angle) * 10 * direction);
// 	// new_y = game->loc_py + (int)(sin(game->player->angle) * 10 * direction);
// 	new_x = game->loc_px + 1 * direction;
// 	new_y = game->loc_py + 1 * direction;


// 	// game->mlx_data[(SCREENWIDTH * SCREENHEIGHT / 2) + SCREENWIDTH / 2 + game->loc_px] = calc_color(game, 'f'); // eski konumu boyama (bunu yorum satırına alıp daha net anlayabilirsiniz hareketi)
// 	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2] = calc_color(game, 'f'); // eski konumu boyama (bunu yorum satırına alıp daha net anlayabilirsiniz hareketi)
// 	game->loc_px = new_x;
// 	game->loc_py = new_y;
// 	printf("game->loc_px: %d\n", game->loc_px);
// 	printf("game->loc_py: %d\n", game->loc_py);
// 	// game->mlx_data[(SCREENWIDTH * SCREENHEIGHT / 2) + SCREENWIDTH / 2 + game->loc_px] = 16777215; // beyaz noktanın ilerlemesi
// 	game->mlx_data[(SCREENWIDTH * (SCREENHEIGHT / 2 + game->loc_py)) + SCREENWIDTH / 2] = 16777215; // beyaz noktanın ilerlemesi

	
// }

void player_game(t_game *game)
{
	if (game->key->w)
		move_ws(game, -1); // yukarı doğru harekette arryin indeksi düşüyor -1 olarak değiştirdim
	if (game->key->s)
		move_ws(game, 1);
	if (game->key->a)
		move_ad(game, -1);
	if (game->key->d)
		move_ad(game, 1);
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
	
	player_game(game);
	// casting_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
	return (0);
}