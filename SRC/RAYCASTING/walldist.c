#include "../../INC/cub3d.h"

void	raydist(t_game *game)
{
    if (game->raycast->side1 == 0)
		game->raycast->perp_dist = game->raycast->sidedist_x - game->raycast->deltadist_x;
	else
		game->raycast->perp_dist = game->raycast->sidedist_y - game->raycast->deltadist_y;
	if (game->raycast->perp_dist < 0.001)
		game->raycast->perp_dist += 0.001;
	game->raycast->height = (int)(SCREENHEIGHT / game->raycast->perp_dist * 2);
	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->start_y < 0)
		game->raycast->start_y = 0;
	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->end_y >= SCREENHEIGHT)
		game->raycast->end_y = SCREENHEIGHT - 1;
}

// void	wall_texture(t_game *game, int x)
// {
// 	double	step;
// 	double	tex_pos;
// 	int		i;
// 	int		tex_y;
// 	int		color;

// 	step = 1.0 * TILE / game->raycast->height;
// 	tex_pos = (game->raycast->start_y - SCREENHEIGHT / 2 + game->raycast->height / 2) * step;
// 	i = game->raycast->start_y;
// 	while (i <= game->raycast->end_y)
// 	{
// 		tex_y = (int)tex_pos & (TILE - 1);
// 		tex_pos += step;
// 		color = c->texture[game->raycast->side1][TILE * tex_y + c->tex_x];
// 		c->tmp[i][x] = color;
// 		i++;
// 	}
// }
