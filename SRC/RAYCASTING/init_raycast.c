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

void init_raycast(t_game *game)
{
	game->img_ptr = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);

	game->mlx_data = (int *)mlx_get_data_addr(game->img_ptr, &game->pixel_bits, &game->line_bytes, &game->endian);
	
	draw_floor_ceiling(game);

	if (!game->img_ptr)
		ft_error("Invalid texture!");
}