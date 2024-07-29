#include "../INC/cub3d.h"

void	game_init(t_game *game, char *str)
{
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// 	ft_error("Mlx doesn't work!");
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map)
		ft_error("Malloc doesn't work!");
	game->img = ft_calloc(sizeof(t_images), 1);
	if (!game->img)
		ft_error("Malloc doesn't work!");
	game->mapname = ft_strdup(str); // freelemeyi unutma
}

char	*fc_texture(char **liner)
{
	int		i;
	int		arr_len;
	char	*rgb;
	char	*tmp;

	i = 0;
	arr_len = ft_arrlen(liner);
	// if (arr_len < 2)
	// 	ft_error("RGB Color is invalid!");
	rgb = NULL;
	tmp = liner[1];
	while (i < arr_len - 1)
	{
		if(rgb == NULL)
			rgb = ft_strdup(liner[i + 1]);
		else
			rgb = ft_strjoin(tmp, liner[i + 1]);
		tmp = rgb;
		i++;
	}
	printf("%s\n", rgb);
	return (rgb);
}

void	put_texture(t_images *img, char **liner)
{
	if (liner[0] == NULL)
		return ;
	if (same_str(liner[0], "NO") == 0 && ft_arrlen(liner) == 2)
		img->north_wall = ft_strdup(liner[1]);
	else if (same_str(liner[0], "SO") == 0 && ft_arrlen(liner) == 2)
		img->south_wall = ft_strdup(liner[1]);
	else if (same_str(liner[0], "WE") == 0 && ft_arrlen(liner) == 2)
		img->west_wall = ft_strdup(liner[1]);
	else if (same_str(liner[0], "EA") == 0 && ft_arrlen(liner) == 2)
		img->east_wall = ft_strdup(liner[1]);
	else if (same_str(liner[0], "F") == 0)
		img->floor = fc_texture(liner);
	else if (same_str(liner[0], "C") == 0)
		img->ceiling = fc_texture(liner);
	else if(same_str(liner[0], "\n") != 0) // isspace islenmeli mi?
		ft_error("Texture path is invalid!");
}

void	texture_init(t_game *game)
{
	int		fd;
	char	*line;
	char	**liner;

	fd = open(game->mapname, O_RDONLY);
	if (fd < 0)
		ft_error("The specified file path is invalid or not found!");
	line = get_next_line(fd);
	while (line)
	{
		liner = ft_split(line, ' ');
		int i = 0;
		while(liner[i] != NULL)
		{
			printf("%s\n", liner[i]);
			i++;
		}
		put_texture(game->img, liner);
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		ft_error("The number of arguments is less than required!");
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		ft_error("Malloc doesn't work!");
	if (argc == 2)
	{
		map_name(argv[1]);
		game_init(game, argv[1]);
		texture_init(game);
		// total_check(game, argv[1]);
		// if (game->map->col_y > 22)
		// 	ft_error("Error\nThis map so big!");
		// game->win = mlx_new_window(game->mlx, game->map->row_x * 64,
		// 		game->map->col_y * 64, "so_long");
		// ft_place(game);
		// mlx_key_hook(game->win, key_hook, game);
		// mlx_hook(game->win, 17, 0L, finish_game, game);
		// mlx_loop(game->mlx);
	}
	else
		ft_error("The number of arguments is more than necessary!");
	return (0);
}