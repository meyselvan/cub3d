#include "../../INC/cub3D.h"

void	fill(t_game *game, int x, int y, char to_fill)
{
	if (y < 0 || y >= game->col || x < 0 || x >= game->row
		|| game->copy_map[y][x] == to_fill
		|| game->copy_map[y][x] == ' '
		|| game->copy_map[y][x] == '*'
		|| game->copy_map[y][x] == '\n')
		return ;
	game->copy_map[y][x] = 'F';
	fill(game, x + 1, y, to_fill);
	fill(game, x - 1, y, to_fill);
	fill(game, x, y + 1, to_fill);
	fill(game, x, y - 1, to_fill);
}

void	map_copy(t_game *game)
{
	int		i;

	i = 0;
	game->copy_map = (char **)malloc(sizeof(char *) * game->col + 1);
	while (i < game->col)
	{
		game->copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->copy_map[i] = NULL;
}

void	fill_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->col)
	{
		j = 0;
		while (j < game->row)
		{
			if (game->copy_map[i][j] == '0' || game->copy_map[i][j] == '1')
			{
				ft_error("Map is not connected!");
			}
			j++;
		}
		i++;
	}
}

void	double_map(t_game *game)
{
	map_copy(game);
	fill(game, game->loc_px, game->loc_py, 'F');
	fill_control(game);
	ft_free_array(game->copy_map);
}
