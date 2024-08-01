#include "../../INC/cub3d.h"

void	fill_star(t_game *game)
{
	int 	len;
	int i;
	int 	count;
	char 	*line;
	int 	tmp_len;

	line = NULL;
	i = 0;
	while (i < game->col)
	{
		len = ft_strlen(game->map[i]) - 1;
		if (game->row == len)
		{
			printf("Row is equal: %s", game->map[i]);
		}
		else if (game->row > len)
		{
			count = game->row - len;
			line = ft_substr(game->map[i], 0, len - 1);
			tmp_len = len;
			while (count + 1 > 0)
			{
				game->map[i] = ft_strjoin(line, "*");
				count--;
				if (line)
					free(line);
				tmp_len++;
				line = ft_substr(game->map[i], 0, tmp_len);
			}
		}
		i++;
	}

}
