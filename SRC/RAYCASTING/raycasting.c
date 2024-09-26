#include "../../INC/cub3D.h"

void	calc_side(t_game *game)
{
	if (game->raycast->raydir_x < 0)
	{
		game->raycast->step_x = -1;
		game->raycast->sidedist_x = (game->player->x - game->loc_px) \
			* game->raycast->deltadist_x;
	}
	else
	{
		game->raycast->step_x = 1;
		game->raycast->sidedist_x = (game->loc_px + 1.0 - game->player->x) \
			* game->raycast->deltadist_x;
	}
	if (game->raycast->raydir_y < 0)
	{
		game->raycast->step_y = -1;
		game->raycast->sidedist_y = (game->player->y - game->loc_py) \
			* game->raycast->deltadist_y;
	}
	else
	{
		game->raycast->step_y = 1;
		game->raycast->sidedist_y = (game->loc_py + 1.0 - game->player->y) \
			* game->raycast->deltadist_y;
	}
}

void	calc_ray(t_game *game, int x)
{
	init_raycast(game, x);
	calc_side(game);
}

void	dda(t_game *game)
{
	while (game->raycast->hit == 0)
	{
		if (game->raycast->sidedist_x < game->raycast->sidedist_y)
		{
			game->raycast->sidedist_x += game->raycast->deltadist_x;
			game->loc_px += game->raycast->step_x;
			if (game->raycast->step_x == 1)
				game->raycast->side1 = 1;
			else
				game->raycast->side1 = 0;
		}
		else
		{
			game->raycast->sidedist_y += game->raycast->deltadist_y;
			game->loc_py += game->raycast->step_y;
			if (game->raycast->step_y == 1)
				game->raycast->side1 = 2;
			else
				game->raycast->side1 = 3;
		}
		if (game->map[game->loc_py][game->loc_px] == '1')
			game->raycast->hit = 1;
	}
}
