#include "../../INC/cub3d.h"

void	check_comp(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != '\0')
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',' && rgb[i] != '\n')
			ft_error("RGB value is invalid!");
		i++;
	}
}

void	check_num(char **liner)
{
	int	i;
	int	j;
	int	count;
	int	flag;

	i = 1;
	count = 0;
	while (liner[i])
	{
		flag = 0;
		j = 0;
		while (liner[i][j] != '\0')
		{
			if (ft_isdigit(liner[i][j]) && flag == 0)
			{
				flag = 1;
				count++;
			}
			if (liner[i][j] == ',')
				flag = 0;
			j++;
		}
		i++;
	}
	if (count != 3)
	{
		ft_free_array(liner);
		ft_error("RGB value is invalid!");
	}
}

char	*fc_texture(char **liner, int arr_len)
{
	int		i;
	char	*rgb;
	char	*tmp;

	i = -1;
	rgb = NULL;
	tmp = liner[1];
	check_num(liner);
	while (++i < arr_len - 1)
	{
		if (rgb)
			free(rgb);
		if (rgb == NULL)
			rgb = ft_strdup(liner[i + 1]);
		else
			rgb = ft_strjoin(tmp, liner[i + 1]);
		tmp = rgb;
	}
	check_comp(rgb);
	if (!rgb_check(rgb))
	{
		if_free(rgb);
		ft_error("RGB value is invalid!");
	}
	return (rgb);
}

void	put_texture(t_images *img, char **liner)
{
	int		arr_len;

	arr_len = ft_arrlen(liner);
	if (same_str(liner[0], "\n"))
		return ;
	else if (same_str(liner[0], "NO")
		&& ft_arrlen(liner) == 2 && !img->north_wall)
		img->north_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "SO")
		&& ft_arrlen(liner) == 2 && !img->south_wall)
		img->south_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "WE")
		&& ft_arrlen(liner) == 2 && !img->west_wall)
		img->west_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "EA")
		&& ft_arrlen(liner) == 2 && !img->east_wall)
		img->east_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "F") && !img->floor)
		img->floor = fc_texture(liner, arr_len);
	else if (same_str(liner[0], "C") && !img->ceiling)
		img->ceiling = fc_texture(liner, arr_len);
	else
		ft_error("Texture is invalid!");
}

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
