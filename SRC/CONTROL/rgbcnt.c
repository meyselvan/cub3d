#include "../../INC/cub3d.h"

int comma_count(char *str)
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

int rgb_check(char *rgb)
{
	int i;
	int s;
    char *tmp;
    int rgbx;

    i = 0;
    tmp = NULL;
    rgbx = 0;
    if (comma_count(rgb) != 2)
        return (0);
    while (rgb[i] != '\0')
    {
        s = i;
        while (rgb[i] != ',' && rgb[i] != '\0')
            i++;
        tmp = ft_substr(rgb, s, i - s);
        if (!tmp)
            return (0);
        if (i - s > 3)
        {
            free(tmp);
            return (0);
        }
        rgbx = atoi(tmp);
        free(tmp);
        if (rgbx < 0 || rgbx > 255)
            return (0);
        if (rgb[i] == ',')
            i++;
    }
    return (1);
}