#include "../../INC/cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	ft_is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
