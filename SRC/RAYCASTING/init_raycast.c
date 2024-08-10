#include "../../INC/cub3d.h"

void init_player(t_game *game)
{
	game->player->x = (double)game->loc_px;
	game->player->y = (double)game->loc_py;

	if(game->playertype == 'N') // N degerlerini tek tek deneyerek buldum digerleri kaldi 
	{
		game->player->dir_x = 0;  // w a s d ile mapte dolasarak x ve y degerlerini takip edin
		game->player->dir_y = -1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if(game->playertype == 'S')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
	else if(game->playertype == 'W')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
	else if(game->playertype == 'E')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
}

void init_raycast(t_game *game, int x)
{

	game->raycast->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	game->raycast->raydir_x = game->player->dir_x + game->player->plane_x * game->raycast->camera_x;
	game->raycast->raydir_y = game->player->dir_y + game->player->plane_y * game->raycast->camera_x;
	game->loc_px = (int)game->player->x;
	game->loc_py = (int)game->player->y;
	game->raycast->deltadist_x = fabs(1 / game->raycast->raydir_x);
	game->raycast->deltadist_y = fabs(1 / game->raycast->raydir_y);
	game->raycast->hit = 0;
}