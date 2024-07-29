#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> // for malloc
# include <unistd.h>
# include <fcntl.h> // for open
# include <math.h>
# include <stdio.h> // for perror
# include <string.h> // for strerror
# include "../MLX/mlx.h"
# include "../LIBFT/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_fd(char *str, int fd);
char	*ft_gnl_strjoin(char *dest, char *src);
char	*ft_getline_fd(char *str);
char	*ft_update_fd(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

typedef struct s_map
{
	char	**all_map;
	char	**copy_map;
}				t_map;

typedef struct s_images
{
	//void	*empty;
	void	*south_wall;
	void	*north_wall;
	void	*east_wall;
	void	*west_wall;
	void 	*floor;
	void	*ceiling;
}			t_images;

typedef struct s_game
{
	t_map		*map;
	t_images	*img;
	void		*mlx;
	void		*win;
	char		*mapname;
	int			loc_px;
	int			loc_py;
}				t_game;

int		ft_error(char *msg);
void	map_name(char *str);
int	ft_arrlen(char **arr);
int	same_str(const char *str1, char *str2);	

#endif