#include "../../INC/cub3d.h"

void	move_ws(t_game *game, int direction)
{
	double	des_x;
	double	des_y;

	des_x = game->player->x + game->player->dir_x * (double)2 / 10 * direction;
	des_y = game->player->y + game->player->dir_y * (double)2 / 10 * direction;
	if (game->map[(int)game->player->y][(int)des_x] == '0')
		game->player->x = des_x;
	if (game->map[(int)des_y][(int)game->player->x] == '0')
		game->player->y = des_y;
}

void	move_ad(t_game *game, int direction)
{
	double	des_x;
	double	des_y;

	des_x = game->player->x + game->player->plane_x
		* (double)2 / 10 * direction;
	des_y = game->player->y + game->player->plane_y
		* (double)2 / 10 * direction;
	if (game->map[(int)game->player->y][(int)des_x] == '0')
		game->player->x = des_x;
	if (game->map[(int)des_y][(int)game->player->x] == '0')
		game->player->y = des_y;
}

void	rotate_player(t_game *game, int direction)
{
	double	old_dirx;
	double	old_planex;
	double	rotate_angle;

	rotate_angle = 0.05 * direction;

	old_dirx = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rotate_angle)
		- game->player->dir_y * sin(rotate_angle);
	game->player->dir_y = old_dirx * sin(rotate_angle)
		+ game->player->dir_y * cos(rotate_angle);

	old_planex = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rotate_angle)
		- game->player->plane_y * sin(rotate_angle);
	game->player->plane_y = old_planex * sin(rotate_angle)
		+ game->player->plane_y * cos(rotate_angle);
}