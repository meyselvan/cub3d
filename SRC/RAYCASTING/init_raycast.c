#include "../../INC/cub3d.h"

void init_player(t_game *game)
{
	if(game->playertype == 'N')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
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

void init_tmp(t_game *game)
{
	int i;

	game->player->tmp = malloc(sizeof(int *) * SCREENHEIGHT);
	if (game->player->tmp == NULL)
		ft_error("Malloc!!");
	i = -1;
	while (++i < SCREENHEIGHT)
	{
		game->player->tmp[i] = malloc(sizeof(int) * SCREENWIDTH);
		if (game->player->tmp[i] == NULL)
			ft_error("Malloc!!");
		ft_bzero(game->player->tmp[i], sizeof(int) * SCREENWIDTH);
	}
}

void init_raycast(t_game *game)
{
	init_player(game);
	init_tmp(game);

	//-------ekrana img basma 

	game->img_ptr = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);

	int w;
	int h;
	game->img_ptr = mlx_xpm_file_to_image(game->mlx, game->img->south_wall, &w, &h);
	if (!game->img_ptr)
		ft_error("Invalid texture!");

	game->buffer = mlx_get_data_addr(game->img_ptr, &game->pixel_bits, &game->line_bytes, &game->endian);

	
	
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);



}