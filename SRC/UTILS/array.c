#include "../../INC/cub3d.h"

int	ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	same_str(const char *str1, char *str2)
{
	int	len1;
	int	len2;
	int	i;

	if (!str1 || !str2)
		return (0);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = 0;
	if (len1 != len2)
		return (0);
	while (i < len1)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	struct_to_array(t_game *game)
{
	t_map	*tmp;
	int		k;
	int		len;

	tmp = game->map_head;
	k = 0;
	len = 0;
	if (game->col > 0)
		game->map = ft_calloc(sizeof(char *), game->col + 1);
	if (game->map == NULL)
		ft_error("Malloc doesn't work!");
	while (tmp && game->col > k)
	{
		if (game->col == k + 1)
			game->map[k] = ft_strdup(tmp->line);
		else
		{
			len = ft_strlen(tmp->line);
			game->map[k] = ft_substr(tmp->line, 0, len - 1);
		}
		tmp = tmp->next;
		k++;
	}
}
