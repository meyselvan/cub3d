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

int	newliner(char **liner, int arr_len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (arr_len == 3)
	{
		tmp = ft_strdup(liner[1]);
		if (same_str(liner[2], "\n"))
		{
			if_free(liner[1]);
			liner[1] = ft_strjoin(tmp, "\n");
			if_free(tmp);
			return (1);
		}
		if_free(tmp);
	}
	return (0);
}
