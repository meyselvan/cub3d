#include "../../INC/cub3d.h"

void	check_component(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			game->playercount++;
			i++;
		}
		else if (str[i] == '\n' || str[i] == '1'
			|| str[i] == '0' || str[i] == ' ')
			i++;
		else
			ft_error("Invalid map component!");
	}
}

void	check_wall(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (str[i] != '1')
		ft_error("Invalid map wall!");
	if (str[len] == '\n')
		len--;
	while (len >= i && str[len] == ' ')
		len--;
	if (len < i || str[len] != '1')
		ft_error("Invalid map wall!");
}

void	map_check(t_game *game)
{
	t_map	*tmp;

	tmp = game->map_head;
	while (tmp)
	{
		if (same_str(tmp->line, "\n"))
			ft_error("Invalid map component!");
		check_component(tmp->line, game);
		if (!ft_is_all_space(tmp->line))
			check_wall(tmp->line);
		tmp = tmp->next;
	}
	if (game->playercount != 1)
		ft_error("Invalid player components!");
}

void	control_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' '
			&& game->map[0][i] != '\n')
			ft_error("Invalid map wall!");
		i++;
	}
	i = 0;
	while (game->map[game->col - 1][i])
	{
		if (game->map[game->col - 1][i] != '1'
			&& game->map[game->col - 1][i] != ' '
			&& game->map[game->col - 1][i] != '\n')
			ft_error("Invalid map wall!");
		i++;
	}
}
