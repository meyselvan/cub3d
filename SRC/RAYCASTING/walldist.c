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
