#include "../../INC/cub3d.h"

double	calc_dis(t_game *game)
{
	if (game->raycast->side1 == 0 || game->raycast->side1 == 1)
	{
		game->raycast->perp_dist = (game->loc_px - game->player->x + (1 - game->raycast->step_x) / 2) / game->raycast->raydir_x;
		if (game->raycast->perp_dist <= 0.000001)
			game->raycast->perp_dist = 0.00001;
		return (game->player->y + game->raycast->perp_dist * game->raycast->raydir_y);
	}
	game->raycast->perp_dist = (game->loc_py - game->player->y + (1 - game->raycast->step_y) / 2) / game->raycast->raydir_y;
	if (game->raycast->perp_dist <= 0.000001)
		game->raycast->perp_dist = 0.00001;
	return (game->player->x + game->raycast->perp_dist * game->raycast->raydir_x);
}

void	calc_wall(t_game *game)
{
	double	wall_x;

	wall_x = calc_dis(game);
	wall_x -= floor(wall_x);
	game->raycast->height = (SCREENHEIGHT / game->raycast->perp_dist);
	game->raycast->tex_x = (int)(wall_x * (double)TILE);
// Dokunun doğru yüzünü kullanmak için düzeltme yap
if (game->raycast->side1 == 0 || game->raycast->side1 == 1)  // Y eksenindeki duvarlar
{
        game->raycast->tex_x = TILE - game->raycast->tex_x - 1;
}
else if (game->raycast->side1 == 2 || game->raycast->side1 == 3)  // X eksenindeki duvarlar
{
        game->raycast->tex_x = TILE - game->raycast->tex_x - 1;
}

	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->start_y < 0)
		game->raycast->start_y = 0;
	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;
	if (game->raycast->end_y >= SCREENHEIGHT)
		game->raycast->end_y = SCREENHEIGHT - 1;
}

void	map_line(t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TILE / game->raycast->height;
	tex_pos = (game->raycast->start_y - SCREENHEIGHT / 2 + game->raycast->height / 2) * step;
	i = game->raycast->start_y;
	while (i <= game->raycast->end_y)
	{
		tex_y = (int)tex_pos & 63;
		tex_pos += step;
		color = game->walls[game->raycast->side1]->addr[(TILE * tex_y) + game->raycast->tex_x ];
		game->mlx_data[i * SCREENWIDTH + x] = color;
		i++;
	}
}










// void	raydist(t_game *game)
// {
//     if (game->raycast->side1 == 0)
// 		game->raycast->perp_dist = game->raycast->sidedist_x - game->raycast->deltadist_x;
// 	else
// 		game->raycast->perp_dist = game->raycast->sidedist_y - game->raycast->deltadist_y;
// 	if (game->raycast->perp_dist < 0.001)
// 		game->raycast->perp_dist += 0.001;
// 	game->raycast->height = (int)(SCREENHEIGHT / game->raycast->perp_dist * 2);
// 	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;
// 	if (game->raycast->start_y < 0)
// 		game->raycast->start_y = 0;
// 	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;
// 	if (game->raycast->end_y >= SCREENHEIGHT)
// 		game->raycast->end_y = SCREENHEIGHT - 1;
// }

// void	ft_texture_helper(t_game *game)
// {
// 	double	wallx;

// 	if (game->raycast->side1 == 0)
// 		wallx = game->player->y + game->raycast->perp_dist * game->raycast->raydir_y;
// 	else
// 		wallx = game->player->x + game->raycast->perp_dist * game->raycast->raydir_x;
// 	wallx -= floor(wallx);
// 	game->raycast->tex_x = (int)(wallx * (double)64);
// 	if (game->raycast->side1 == 0 && game->raycast->raydir_x > 0)
// 		game->raycast->tex_x = 64 - game->raycast->tex_x - 1;
// 	if (game->raycast->side1 == 1 && game->raycast->raydir_y < 0)
// 		game->raycast->tex_x = 64 - game->raycast->tex_x - 1;
// 	game->raycast->tex_step = 1.0 * 64 / game->raycast->height;
// 	game->raycast->tex_pos = (game->raycast->start_y - SCREENHEIGHT
// 			/ 2 + game->raycast->height / 2) * game->raycast->tex_step;
// }

// void	ft_draw_wall_texture(t_game *game, int x, int tex_index)
// {
// 	int			texy;

// 	while (game->raycast->start_y < game->raycast->end_y)
// 	{
// 		texy = (int)game->raycast->tex_pos & 63;
// 		game->raycast->tex_pos += game->raycast->tex_step;
// 		if (game->walls[tex_index]->addr[64 * texy + game->raycast->tex_x] > 0)
// 			game->mlx_data[game->raycast->start_y * SCREENWIDTH + x]
// 				= game->walls[tex_index]->addr[64 * texy + game->raycast->tex_x];
// 		game->raycast->start_y++;
// 	}
// }

// void	ft_draw_wall_side(t_game *game, int x)
// {
// 	ft_texture_helper(game);
// 	if (game->raycast->side1 == 0 && game->raycast->raydir_x > 0)
// 		ft_draw_wall_texture(game, x, 0);
// 	else if (game->raycast->side1 == 0 && game->raycast->raydir_x < 0)
// 		ft_draw_wall_texture(game, x, 1);
// 	else if (game->raycast->side1 == 1 && game->raycast->raydir_y > 0)
// 		ft_draw_wall_texture(game, x, 2);
// 	else
// 		ft_draw_wall_texture(game, x, 3);
// }

