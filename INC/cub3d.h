#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "../MLX/mlx.h"
# include "../LIBFT/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SCREENHEIGHT 1000
# define SCREENWIDTH 1500
# define TILE 64

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct s_images
{
	char	*south_wall;
	char	*north_wall;
	char	*east_wall;
	char	*west_wall;
	char	*floor;
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
}				t_player;

typedef struct s_raycast
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			side1;
	int			hit;

	int			tex_x;
	int			tex_y;

	double		perp_dist;
	int			height;
	int			start_y;
	int			end_y;
}				t_raycast;

typedef struct s_textures
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}				t_textures;

typedef struct s_game
{
	t_map		*map_head;
	t_map		*map_tail;
	t_images	*img;
	t_keycode	*key;
	t_player	*player;
	t_raycast	*raycast;
	t_textures	*walls[4];

	void		*mlx;
	void		*win;

	void		*img_ptr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	int			*mlx_data;

	char		**map;
	char		**copy_map;
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
char	*fc_texture(char **liner, int arr_len);
void	put_texture(t_images *img, char **liner);
void	texture_init(t_game *game);
void	set_walls(t_game *game);
int		rgb_check(char *rgb);
void	add_map_node(t_game *game, char *line);
int		comma_count(char *str);
void	xpm_name(char *str);
void	map_check(t_game *game);
void	del_map_node_from_head(t_game *game);
int		ft_is_all_space(char *str);
void	del_map_node_from_tail(t_game *game);
int		ft_isspace(char c);
int		ft_is_all_space(char *str);
void	fill_star(t_game *game);
void	struct_to_array(t_game *game);
void	flood_fill(t_game *game);
int		exit_game(t_game *game);
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
int		game_hook(void *param);
void	init_screen(t_game *game);

void	init_raycast(t_game *game, int x);
void	init_player(t_game *game);

int		calc_color(t_game *game, char c_or_f);
void	set_cf_texture(t_game *game);
void	draw_floor_ceiling(t_game *game);

void	calc_ray(t_game *game, int x);
void	dda(t_game *game);

double	calc_dis(t_game *game);
void	calc_wall(t_game *game);
void	map_line(t_game *game, int x);

void	ft_free_struct(t_game *game);
void	ft_free_array(char **arr);

void	move_ws(t_game *game, int direction);
void	move_ad(t_game *game, int direction);
void	rotate_player(t_game *game, int direction);

int		all_texture(t_images *img);
int		true_texture(t_images *img);
void	control_line(t_game *game);
void	if_free(char *line);
void	double_map(t_game *game);
void	control_newline(t_game *game);

#endif