#include "../../INC/cub3D.h"

void	xpm_to_img(t_game *game, char *path, int index)
{
	game->walls[index] = malloc(sizeof(t_textures));
	if (!game->walls[index])
		ft_error("Malloc doesn't work!");
	game->walls[index]->img = mlx_xpm_file_to_image(game->mlx, path,
			&game->walls[index]->w, &game->walls[index]->h);
	if (!game->walls[index]->img)
		ft_error("Texture doesn't work!");
	game->walls[index]->addr = \
	(int *)mlx_get_data_addr(game->walls[index]->img, \
	&game->walls[index]->bpp, &game->walls[index]->line_len, \
	&game->walls[index]->endian);
	if (!game->walls[index]->addr)
		ft_error("Texture doesn't work!");
	if (!game->walls[index]->addr)
		ft_error("Texture doesn't work!");
}

void	set_walls(t_game *game)
{
	xpm_to_img(game, game->img->west_wall, 1);
	xpm_to_img(game, game->img->east_wall, 0);
	xpm_to_img(game, game->img->south_wall, 3);
	xpm_to_img(game, game->img->north_wall, 2);
}
