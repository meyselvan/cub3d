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
	game->buffer = mlx_get_data_addr(game->img_ptr, &game->pixel_bits, &game->line_bytes, &game->endian);

	int color = 0xABCDEF;

	if (game->pixel_bits != 32)
		color = mlx_get_color_value(game->mlx, color);

	for(int y = 0; y < SCREENHEIGHT; ++y)
	for(int x = 0; x < SCREENWIDTH; ++x)
	{
		int pixel = (y * game->line_bytes) + (x * 4);

		if (game->endian == 1)        // Most significant (Alpha) byte first
		{
			game->buffer[pixel + 0] = (color >> 24);
			game->buffer[pixel + 1] = (color >> 16) & 0xFF;
			game->buffer[pixel + 2] = (color >> 8) & 0xFF;
			game->buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (game->endian == 0)   // Least significant (Blue) byte first
		{
			game->buffer[pixel + 0] = (color) & 0xFF;
			game->buffer[pixel + 1] = (color >> 8) & 0xFF;
			game->buffer[pixel + 2] = (color >> 16) & 0xFF;
			game->buffer[pixel + 3] = (color >> 24);
		}
	}

	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);



}