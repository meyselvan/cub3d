#include "../../INC/cub3d.h"

void	can_be_opened(char *str)
{
	int	i;

	i = open(str, O_RDONLY);
	if (i < 0)
		ft_error("The specified file path is invalid or not found!");
	close(i);

}

void	xpm_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 4)
	{
		if (str[len - 1] == 'm' && str[len - 2] == 'p'
			&& str[len - 3] == 'x' && str[len - 4] == '.')
			can_be_opened(str);
		else
			ft_error("Invalid file extension name, try again");
		can_be_opened(str);
	}
	else
		ft_error("Invalid file name, try again.");
}

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
			ft_error("Invalid file extension name, try again");
		i = open(str, O_RDONLY);
		if (i < 0)
			ft_error("The specified file path is invalid or not found!");
		close(i);
	}
	else
		ft_error("Invalid file name, try again.");
}


