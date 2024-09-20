#include "../../INC/cub3d.h"

int	all_texture(t_images *img)
{
	if (img->north_wall && img->south_wall && img->west_wall
		&& img->east_wall && img->floor && img->ceiling)
		return (1);
	return (0);
}

int	true_texture(t_images *img)
{
	xpm_name(img->north_wall);
	xpm_name(img->south_wall);
	xpm_name(img->west_wall);
	xpm_name(img->east_wall);
	return (1);
}
