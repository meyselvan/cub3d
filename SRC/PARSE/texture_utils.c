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

int	check_line(char *line)
{
	int	j;
	int	flag;
	int	count;

	j = 0;
	flag = 0;
	count = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (line[j] == ',')
			flag = 0;
		j++;
	}
	return (count);
}

void	check_num(char **liner)
{
	int	i;
	int	total_count;

	i = 1;
	total_count = 0;
	while (liner[i])
	{
		total_count += check_line(liner[i]);
		i++;
	}
	if (total_count != 3)
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
	else if (same_str(liner[0], "NO") && (ft_arrlen(liner) == 2
			|| newliner(liner, arr_len)) && !img->north_wall)
		img->north_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "SO") && (ft_arrlen(liner) == 2
			|| newliner(liner, arr_len)) && !img->south_wall)
		img->south_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "WE") && (ft_arrlen(liner) == 2
			|| newliner(liner, arr_len)) && !img->west_wall)
		img->west_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "EA") && (ft_arrlen(liner) == 2
			|| newliner(liner, arr_len)) && !img->east_wall)
		img->east_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "F") && !img->floor)
		img->floor = fc_texture(liner, arr_len);
	else if (same_str(liner[0], "C") && !img->ceiling)
		img->ceiling = fc_texture(liner, arr_len);
	else
		ft_error("Texture is invalid!");
}
