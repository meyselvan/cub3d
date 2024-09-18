#include "../../INC/cub3d.h"

char	*true_case(t_game *game, int fd, char *line)
{
	if (line)
		free(line);
	line = get_next_line(fd);
	while (line)
	{
		add_map_node(game, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (line);
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
			line = true_case(game, fd, line);
		else
		{
			if (line)
				free(line);
			line = get_next_line(fd);
		}
	}
	if (line)
		free(line);
	close(fd);
}
