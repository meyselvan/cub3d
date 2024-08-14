#include "../../INC/cub3d.h"

// void	raydist(t_game *game)
// {
//     if (game->raycast->side1 == 0)
// 		game->raycast->perp_dist = game->raycast->sidedist_x - game->raycast->deltadist_x;
// 	else
// 		game->raycast->perp_dist = game->raycast->sidedist_y - game->raycast->deltadist_y;
// 	if (game->raycast->perp_dist < 0.001)
// 		game->raycast->perp_dist += 0.001;
// 	game->raycast->height = (int)(SCREENHEIGHT / game->raycast->perp_dist * 2);
// 	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;
// 	if (game->raycast->start_y < 0)
// 		game->raycast->start_y = 0;
// 	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;
// 	if (game->raycast->end_y >= SCREENHEIGHT)
// 		game->raycast->end_y = SCREENHEIGHT - 1;
// }

double	calc_dis(t_game *game)
{
	if (game->raycast->side1 == 0 || game->raycast->side1 == 1)
	{
		game->raycast->perp_dist = (game->loc_px - game->player->x + (1 - game->raycast->step_x) / 2) / game->raycast->raydir_x;
		if (game->raycast->perp_dist <= 0.000001)
			game->raycast->perp_dist = 0.00001;
		return (game->player->y + game->raycast->perp_dist * game->raycast->raydir_y);
	}
	game->raycast->perp_dist = (game->loc_py - game->player->y + (1 - game->raycast->step_y) / 2) / game->raycast->raydir_y;
	if (game->raycast->perp_dist <= 0.000001)
		game->raycast->perp_dist = 0.00001;
	return (game->player->x + game->raycast->perp_dist * game->raycast->raydir_x);
}

void	calc_wall(t_game *game)
{
	double	wall_x;

	wall_x = calc_dis(game);
	wall_x -= floor(wall_x);
	game->raycast->height = (SCREENHEIGHT / game->raycast->perp_dist);
	game->raycast->side2 = game->raycast->side1;
	game->raycast->tex_x = (int)(wall_x * (double)TILE);
	if (((game->raycast->side1 == 0) || (game->raycast->side1 == 1)) && game->raycast->raydir_x < 0)
		game->raycast->tex_x = TILE - game->raycast->tex_x - 1;
	if (((game->raycast->side1 == 2) || (game->raycast->side1 == 3)) && game->raycast->raydir_y > 0)
		game->raycast->tex_x = TILE - game->raycast->tex_x - 1;
	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->start_y < 0)
		game->raycast->start_y = 0;
	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->end_y >= SCREENHEIGHT)
		game->raycast->end_y = SCREENHEIGHT - 1;
}

void	map_line(t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TILE / game->raycast->height;
	tex_pos = (game->raycast->start_y - SCREENHEIGHT / 2 + game->raycast->height / 2) * step;
	i = game->raycast->start_y;
	while (i <= game->raycast->end_y)
	{
		tex_y = (int)tex_pos & (TILE - 1);
		tex_pos += step;
		color = game->walls[game->raycast->side2]->addr[(TILE * tex_y * 2) + game->raycast->tex_x * 2];
		game->mlx_data[i * SCREENWIDTH + x] = color;
		i++;
	}
}
