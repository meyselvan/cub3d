#include "../../INC/cub3d.h"

void	map_name(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len >= 4)
	{
		if (str[len - 1] == 'b' && str[len - 2] == 'u'
			&& str[len - 3] == 'c' && str[len - 4] == '.')
			return ;
		else
			ft_error("Error\nInvalid file extension name, try again");
		i = open(str, O_RDONLY);
		if (i < 0)
			ft_error("Error\nThe specified file path is invalid or not found!");
		close(i);
	}
	else
		ft_error("Error\nInvalid file name, try again.");
}


