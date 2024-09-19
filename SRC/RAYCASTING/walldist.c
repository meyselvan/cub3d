#include "../../INC/cub3d.h"

double	calc_dis(t_game *game)
{
	// Eğer ışın yatay (X ekseni) boyunca gidiyorsa
	if (game->raycast->side1 == 0 || game->raycast->side1 == 1)
	{
		// X eksenindeki mesafeyi hesapla
		game->raycast->perp_dist = (game->loc_px - game->player->x \
		+ (1 - game->raycast->step_x) / 2) / game->raycast->raydir_x;

		// Eğer hesaplanan mesafe çok küçükse, sıfıra yaklaşmaması için küçük bir değer ata
		if (game->raycast->perp_dist <= 0.000001)
			game->raycast->perp_dist = 0.00001;

		// Y ekseninde varılan noktanın koordinatını döndür
		return (game->player->y + game->raycast->perp_dist \
				* game->raycast->raydir_y);
	}

	// Eğer ışın dikey (Y ekseni) boyunca gidiyorsa
	game->raycast->perp_dist = (game->loc_py - game->player->y \
		+ (1 - game->raycast->step_y) / 2) / game->raycast->raydir_y;

	// Eğer hesaplanan mesafe çok küçükse, sıfıra yaklaşmaması için küçük bir değer ata
	if (game->raycast->perp_dist <= 0.000001)
		game->raycast->perp_dist = 0.00001;

	// X ekseninde varılan noktanın koordinatını döndür
	return (game->player->x + game->raycast->perp_dist \
			* game->raycast->raydir_x);
}

void	calc_wall(t_game *game)
{
	double	wall_x;

	// Duvara olan mesafeyi hesapla
	wall_x = calc_dis(game);

	// Duvarın X eksenindeki kesişme noktasını hesapla ve tam sayıyı çıkar
	wall_x -= floor(wall_x);

	// Duvarın ekrandaki yüksekliğini hesapla
	game->raycast->height = (SCREENHEIGHT / game->raycast->perp_dist);

	// Duvarın dokudaki X eksenindeki yerini hesapla
	game->raycast->tex_x = (int)(wall_x * (double)TILE);

	// Eğer X ekseninde gidiliyorsa dokunun X ekseni koordinatını ters çevir
	if (game->raycast->side1 == 0 || game->raycast->side1 == 1)
		game->raycast->tex_x = TILE - game->raycast->tex_x - 1;

	// Eğer Y ekseninde gidiliyorsa dokunun X ekseni koordinatını ters çevir
	else if (game->raycast->side1 == 2 || game->raycast->side1 == 3)
		game->raycast->tex_x = TILE - game->raycast->tex_x - 1;

	// Ekranda duvarın nereden başlayacağını hesapla
	game->raycast->start_y = -game->raycast->height / 2 + SCREENHEIGHT / 2;

	// Eğer başlangıç noktasını ekran sınırlarına göre ayarla
	if (game->raycast->start_y < 0)
		game->raycast->start_y = 0;

	// Duvarın nerede biteceğini hesapla
	game->raycast->end_y = game->raycast->height / 2 + SCREENHEIGHT / 2;

	// Eğer bitiş noktası ekranın sınırlarını geçiyorsa, sınırla
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

	// Her bir pikselin texture'daki adımını hesapla
	step = 1.0 * TILE / game->raycast->height;

	// Texture'ın hangi noktasından başlanacağını hesapla
	tex_pos = (game->raycast->start_y - SCREENHEIGHT \
				/ 2 + game->raycast->height / 2) * step;

	// Başlangıç pikseli
	i = game->raycast->start_y;

	// Başlangıç pikselinden bitiş pikseline kadar ilerle
	while (i <= game->raycast->end_y)
	{
		// Y eksenindeki texture koordinatını hesapla
		tex_y = (int)tex_pos & 63;

		// Texture'daki adımın ilerlemesini sağla
		tex_pos += step;

		// Texture'ın ilgili rengini al
		color = game->walls[game->raycast->side1]->addr[(TILE * tex_y) \
			+ game->raycast->tex_x];

		// Rengi ekranda doğru piksele yerleştir
		game->mlx_data[i * SCREENWIDTH + x] = color;

		// Bir sonraki piksele geç
		i++;
	}
}
