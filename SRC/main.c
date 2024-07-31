#include "../INC/cub3d.h"

void	game_init(t_game *game, char *str)
{
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// 	ft_error("Mlx doesn't work!");
	game->map_head = ft_calloc(sizeof(t_map), 1);
	if (!game->map_head)
		ft_error("Malloc doesn't work!");
	game->img = ft_calloc(sizeof(t_images), 1);
	if (!game->img)
		ft_error("Malloc doesn't work!");
	game->mapname = ft_strdup(str); // freelemeyi unutma
	game->map_tail = NULL;
	game->map_head = NULL;
	game->playercount = 0;
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
		map_name(argv[1]);
		game_init(game, argv[1]);
		texture_init(game);
		del_map_node_from_head(game);
		del_map_node_from_tail(game);
		map_check(game);
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
