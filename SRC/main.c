#include "../INC/cub3d.h"

void	game_init(t_game *game, char *str)
{
	map_name(str);
	game->map_head = ft_calloc(sizeof(t_map), 1);
	if (!game->map_head)
		ft_error("Malloc doesn't work!");
	game->img = ft_calloc(sizeof(t_images), 1);
	if (!game->img)
		ft_error("Malloc doesn't work!");
	game->key = ft_calloc(sizeof(t_keycode), 1);
	if (!game->key)
		ft_error("Malloc doesn't work!");
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		ft_error("Malloc doesn't work!");
	game->raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!game->raycast)
		ft_error("Malloc doesn't work!");
	game->mapname = ft_strdup(str);
	free(game->map_head);
	game->map_tail = NULL;
	game->map_head = NULL;
	game->playercount = 0;
	texture_init(game);
	del_map_node_from_head(game);
	del_map_node_from_tail(game);
}

void	player_loc(t_game *game, t_map *node)
{
	t_map	*tmp;
	int		i;
	int		j;

	tmp = node;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'N' || tmp->line[i] == 'S'
				|| tmp->line[i] == 'W' || tmp->line[i] == 'E')
			{
				game->loc_px = i;
				game->loc_py = j;
				game->playertype = tmp->line[i];
				tmp->line[i] = '0';
				return ;
			}
			i++;
		}
		tmp = tmp->next;
		j++;
	}
}

void	count_row_col(t_game *game)
{
	t_map	*tmp;
	int		i;
	int		j;

	tmp = game->map_head;
	i = 0;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i] && tmp->line[i] != '\n')
			i++;
		if (i > game->row)
			game->row = i;
		j++;
		tmp = tmp->next;
	}
	game->col = j;
}
#include <stdio.h>

void	init_cub(t_game *game, char **argv)
{
	game_init(game, argv[1]);
	map_check(game);
	player_loc(game, game->map_head);
	count_row_col(game);
	struct_to_array(game);
	control_line(game);
	fill_star(game);
	flood_fill(game);
	double_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Mlx doesn't work!");
	game->win = mlx_new_window(game->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
	init_screen(game);
	init_player(game);
	set_walls(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		ft_error("The number of arguments is less than required!");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("Malloc doesn't work!");
	if (argc == 2)
	{
		init_cub(game, argv);
		mlx_loop_hook(game->mlx, game_hook, game);
		mlx_hook(game->win, 3, 0, key_released, game);
		mlx_hook(game->win, 2, 0, key_pressed, game);
		mlx_hook(game->win, 17, 0, exit_game, game);
		mlx_loop(game->mlx);
		ft_free_struct(game);
		free(game);
	}
	else
		ft_error("The number of arguments is more than necessary!");
	return (0);
}
