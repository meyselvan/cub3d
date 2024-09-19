#include "../../INC/cub3d.h"

void	if_free(char *line)
{
	if (line)
		free(line);
}

void	fill_star(t_game *game)
{
	int		len;
	int		i;
	int		count;
	char	*line;
	int		tmp_len;

	line = NULL;
	i = 0;
	while (i < game->col)
	{
		len = ft_strlen(game->map[i]);
		if (game->row > len)
		{
			count = game->row - len;
			if_free(line);
			line = ft_substr(game->map[i], 0, len);
			tmp_len = len;
			while (count + 1 > 0)
			{
				if (game->map[i])
					free(game->map[i]);
				game->map[i] = ft_strjoin(line, "*");
				count--;
				if_free(line);
				tmp_len++;
				line = ft_substr(game->map[i], 0, tmp_len);
			}
		}
		i++;
	}
	if_free(line);
}

void	control_four_direction(char **tmp, int j, int i)
{
	int	len;

	len = ft_strlen(tmp[j]);
	if (tmp[j][i] == '0' || tmp[j][i] == 'N' || tmp[j][i] == 'S'
		|| tmp[j][i] == 'W' || tmp[j][i] == 'E')
	{
		if (i - 1 >= 0 && (tmp[j][i - 1] == ' ' || tmp[j][i - 1] == '*'))
			ft_error("Map is not closed!");
		if (i + 1 < len && (tmp[j][i + 1] == ' ' || tmp[j][i + 1] == '*'))
			ft_error("Map is not closed!");
		if (j - 1 >= 0 && (tmp[j - 1][i] == ' ' || tmp[j - 1][i] == '*'))
			ft_error("Map is not closed!");
		if (j + 1 < ft_arrlen(tmp) && (tmp[j + 1][i] == ' '
			|| tmp[j + 1][i] == '*'))
			ft_error("Map is not closed!");
	}
}

void	flood_fill(t_game *game)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	tmp = game->map;
	while (j < game->col)
	{
		i = 0;
		while (i < game->row)
		{
			if (tmp[j][i] == '0' || tmp[j][i] == 'N' || tmp[j][i] == 'S'
				|| tmp[j][i] == 'W' || tmp[j][i] == 'E')
				control_four_direction(tmp, j, i);
			i++;
		}
		j++;
	}
}
