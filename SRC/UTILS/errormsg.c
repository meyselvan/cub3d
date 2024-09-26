#include "../../INC/cub3D.h"

int	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	system("leaks cub3D");
	exit (0);
}
