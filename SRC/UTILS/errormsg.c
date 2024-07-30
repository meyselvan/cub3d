#include "../../INC/cub3d.h"

int	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit (0);
}
