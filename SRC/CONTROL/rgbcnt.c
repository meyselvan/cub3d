#include "../../INC/cub3D.h"

int	comma_count(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	loop_rgb(char *rgb, char *tmp, int rgbx, int i)
{
	int	s;

	i = 0;
	while (rgb[i] != '\0')
	{
		s = i;
		while (rgb[i] != ',' && rgb[i] != '\0')
			i++;
		if (tmp)
			free(tmp);
		tmp = ft_substr(rgb, s, i - s);
		if (!tmp)
			return (0);
		rgbx = atoi(tmp);
		if (i - s > 3 || rgbx < 0 || rgbx > 255)
		{
			free(tmp);
			return (0);
		}
		if (rgb[i] == ',')
			i++;
	}
	free(tmp);
	return (1);
}

int	rgb_check(char *rgb_tmp)
{
	char	*tmp;
	int		rgbx;
	char	*rgb;

	tmp = NULL;
	rgbx = 0;
	rgb = ft_substr(rgb_tmp, 0, ft_strlen(rgb_tmp) - 1);
	if (comma_count(rgb) != 2)
	{
		free(rgb);
		return (0);
	}
	if (loop_rgb(rgb, tmp, rgbx, 0) == 0)
	{
		free(tmp);
		free(rgb);
		return (0);
	}
	free(tmp);
	free(rgb);
	return (1);
}
