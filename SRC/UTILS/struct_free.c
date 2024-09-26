#include "../../INC/cub3D.h"

void	free_map(t_game *game)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = game->map_head;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = tmp2;
	}
}

void	free_img(t_images *img)
{
	free(img->ceiling);
	free(img->floor);
	if (img->north_wall)
		free(img->north_wall);
	if (img->south_wall)
		free(img->south_wall);
	if (img->east_wall)
		free(img->east_wall);
	if (img->west_wall)
		free(img->west_wall);
	free(img);
}

void	ft_free_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->walls[i])
		{
			if (game->walls[i]->img)
				mlx_destroy_image(game->mlx, game->walls[i]->img);
			free(game->walls[i]);
		}
		i++;
	}
}

void	ft_free_struct(t_game *game)
{
	free_map(game);
	free_img(game->img);
	free(game->key);
	free(game->player);
	free(game->raycast);
	free(game->mapname);
	ft_free_array(game->map);
	free(game->win);
	free(game->mlx);
	free(game->mlx_data);
	ft_free_walls(game);
	free(game->img_ptr);
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
