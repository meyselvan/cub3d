#include "../../INC/cub3d.h"

void init_screen(t_game *game)
{
	game->img_ptr = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!game->img_ptr)
		ft_error("img_ptr error!");

	game->mlx_data = (int *)mlx_get_data_addr(game->img_ptr, &game->pixel_bits, &game->line_bytes, &game->endian);
	set_cf_texture(game);

}