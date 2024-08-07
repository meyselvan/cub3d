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

# define SCREENHEIGHT 512 
# define SCREENWIDTH 1280

typedef struct s_map
{
	char	*line;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct s_images
{
	char	*south_wall;
	char	*north_wall;
	char	*east_wall;
	char	*west_wall;
	char 	*floor;
	char	*ceiling;
	int		floor_texture;
	int		ceiling_texture;
}			t_images;

typedef struct s_keycode
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_keycode;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		angle;

	int			**tmp;
}				t_player;

typedef struct s_game
{
	t_map		*map_head;
	t_map 		*map_tail;
	t_images	*img;
	t_keycode	*key;
	t_player	*player;

	void		*mlx;
	void		*win;

	//goruntu isleme
	void		*img_ptr;
	int 		pixel_bits;
	int 		line_bytes;
	int 		endian;
	int			*mlx_data;

	char 		**map;
	char		*mapname;

	int			playercount;
	char		playertype;
	int			loc_px;
	int			loc_py;
	int			row;
	int			col;

}				t_game;


char	*get_next_line(int fd);
char	*ft_read_fd(char *str, int fd);
char	*ft_gnl_strjoin(char *dest, char *src);
char	*ft_getline_fd(char *str);
char	*ft_update_fd(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_error(char *msg);
void	map_name(char *str);
int		ft_arrlen(char **arr);
int		same_str(const char *str1, char *str2);	
char	*fc_texture(char **liner);
void	put_texture(t_images *img, char **liner);
void	texture_init(t_game *game);
int		rgb_check(char *rgb);
void add_map_node(t_game *game, char *line);
int		comma_count(char *str);
void	xpm_name(char *str);
void	map_check(t_game *game);
void del_map_node_from_head(t_game *game);
int ft_is_all_space(char *str);
void del_map_node_from_tail(t_game *game);
int ft_isspace(char c);
int ft_is_all_space(char *str);
void	fill_star(t_game *game);
void	struct_to_array(t_game *game);
void flood_fill(t_game *game);
int	exit_game(t_game *game);
int key_pressed(int keycode, t_game *game);
int key_released(int keycode, t_game *game);
int game_hook(void *param);

//raycasting
void init_raycast(t_game *game);

int calc_color(t_game *game, char c_or_f);
void set_cf_texture(t_game *game);

#endif