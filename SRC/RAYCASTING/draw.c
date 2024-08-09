#include "../../INC/cub3d.h"

void draw_map2d(t_game *game)
{
	int x = 0;
	int y = 0;
	int i = 0;
	while (y < game->col * 50)
	{
		i = 0;
		while (i < game->row * 50)
		{
			if (game->map[y/50][i/50] && game->map[y/50][i/50] != '0' && game->map[y/50][i/50] != 'N')
				game->mlx_data[x] = 0;
			else
				game->mlx_data[x] = 16777215;
			i++;
			x++;
		}
		x = SCREENWIDTH * y;
		y++;
	}
}
