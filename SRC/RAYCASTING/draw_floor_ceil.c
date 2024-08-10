#include "../../INC/cub3d.h"

int calc_color(t_game *game, char c_or_f)
{
    int color;
    char **rgb;
    int i;

    if (c_or_f == 'c')
        rgb = ft_split(game->img->ceiling, ',');
    else
        rgb = ft_split(game->img->floor, ',');

    i = 0;
    while (rgb[i])
        i++;

    if (i != 3) // son degerin bos olma durumu kontrolu ama calismiyor split yuzunden
        ft_error("Invalid RGB value\n");

    color = ft_atoi(rgb[0]) * 65536 + ft_atoi(rgb[1]) * 256 + ft_atoi(rgb[2]);
    
    free(rgb);
    return (color);
}

void set_cf_texture(t_game *game)
{
	game->img->ceiling_texture = calc_color(game, 'c');
	game->img->floor_texture = calc_color(game, 'f');
}

void draw_floor_ceiling(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < SCREENHEIGHT / 2)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			game->mlx_data[i * SCREENWIDTH + n] = game->img->ceiling_texture;
			n++;
		}
		i++;
	}
	while (i < SCREENHEIGHT)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			game->mlx_data[i * SCREENWIDTH + n] = game->img->floor_texture;
			n++;
		}
		i++;
	}
}