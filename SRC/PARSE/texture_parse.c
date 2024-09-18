#include "../../INC/cub3d.h"

char	*fc_texture(char **liner)
{
	int		i;
	int		arr_len;
	char	*rgb;
	char	*tmp;

	i = 0;
	arr_len = ft_arrlen(liner);
	rgb = NULL;
	tmp = liner[1];
	while (i < arr_len - 1)
	{
		if (rgb)
			free(rgb);
		if (rgb == NULL)
			rgb = ft_strdup(liner[i + 1]);
		else
			rgb = ft_strjoin(tmp, liner[i + 1]);
		tmp = rgb;
		i++;
	}
	// if (rgb_check(rgb) == 0)
	// 	return (NULL);
	return (rgb);
}

void	put_texture(t_images *img, char **liner)
{
	if (same_str(liner[0], "\n"))
		return ;
	else if (same_str(liner[0], "NO") && ft_arrlen(liner) == 2 && !img->north_wall)
		img->north_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "SO") && ft_arrlen(liner) == 2 && !img->south_wall)
		img->south_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "WE") && ft_arrlen(liner) == 2 && !img->west_wall)
		img->west_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "EA") && ft_arrlen(liner) == 2 && !img->east_wall)
		img->east_wall = ft_substr(liner[1], 0, ft_strlen(liner[1]) - 1);
	else if (same_str(liner[0], "F") && !img->floor)
		img->floor = fc_texture(liner);
	else if (same_str(liner[0], "C") && !img->ceiling)
		img->ceiling = fc_texture(liner);
	else
		ft_error("Texture is invalid!");
}

int	all_texture(t_images *img)
{
	if (img->north_wall && img->south_wall && img->west_wall 
			&& img->east_wall && img->floor && img->ceiling)
		return (1);
	return (0);
}

int	true_texture(t_images *img)
{
	xpm_name(img->north_wall);
	xpm_name(img->south_wall);
	xpm_name(img->west_wall);
	xpm_name(img->east_wall);
	return (1);
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
		put_texture(game->img, liner);
		ft_free_array(liner);
		if (all_texture(game->img) && true_texture(game->img))
		{
			if(line)
				free(line);
			line = get_next_line(fd);
			while (line)
			{
				add_map_node(game, line);
				if (line)
					free(line);
				line = get_next_line(fd);
			}
		}
		else
		{
			if (line)
				free(line);
			line = get_next_line(fd);
		}
	}
	if (line)
		free(line);
	// if (!all_texture(game->img))
	// 	ft_error("Missing texture!");
	close(fd);
}