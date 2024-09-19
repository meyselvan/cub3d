#include "../../INC/cub3d.h"

void	init_player_pos(t_game *game)
{
	// Eğer oyuncu batıya (W) bakıyorsa
	if (game->playertype == 'W')
	{
		// Oyuncunun yönünü ve kamera düzlemindeki pozisyonunu belirle
		game->player->dir_x = -1;  // X ekseninde batıya doğru bakıyor
		game->player->dir_y = 0;   // Y ekseninde hareket yok
		game->player->plane_x = 0;  // Kamera düzlemi X ekseni boyunca genişlemiyor
		game->player->plane_y = -0.66;  // Kamera düzlemi Y ekseninde sola doğru genişliyor
	}
	// Eğer oyuncu doğuya (E) bakıyorsa
	else if (game->playertype == 'E')
	{
		// Oyuncunun yönünü ve kamera düzlemindeki pozisyonunu belirle
		game->player->dir_x = 1;  // X ekseninde doğuya doğru bakıyor
		game->player->dir_y = 0;  // Y ekseninde hareket yok
		game->player->plane_x = 0;  // Kamera düzlemi X ekseni boyunca genişlemiyor
		game->player->plane_y = 0.66;  // Kamera düzlemi Y ekseninde sağa doğru genişliyor
	}
}

void	init_player(t_game *game)
{
	// Oyuncunun başlangıç pozisyonunu belirle
	game->player->x = (double)game->loc_px;
	game->player->y = (double)game->loc_py;

	// Eğer oyuncu kuzeye (N) bakıyorsa
	if (game->playertype == 'N')
	{
		// Oyuncunun yönünü ve kamera düzlemini belirle
		game->player->dir_x = 0;  // X ekseninde hareket yok
		game->player->dir_y = -1;  // Y ekseninde kuzeye doğru bakıyor
		game->player->plane_x = 0.66;  // Kamera düzlemi X ekseninde sağa doğru genişliyor
		game->player->plane_y = 0;  // Y ekseninde genişleme yok
	}
	// Eğer oyuncu güneye (S) bakıyorsa
	else if (game->playertype == 'S')
	{
		// Oyuncunun yönünü ve kamera düzlemini belirle
		game->player->dir_x = 0;  // X ekseninde hareket yok
		game->player->dir_y = 1;  // Y ekseninde güneye doğru bakıyor
		game->player->plane_x = -0.66;  // Kamera düzlemi X ekseninde sola doğru genişliyor
		game->player->plane_y = 0;  // Y ekseninde genişleme yok
	}

	// Oyuncunun doğu veya batıya bakma durumunu ayrı fonksiyonda başlat
	init_player_pos(game);
}

void	init_raycast(t_game *game, int x)
{
	// Kameranın X eksenindeki pozisyonunu hesapla ([-1, 1] aralığında)
	game->raycast->camera_x = 2 * x / (double)SCREENWIDTH - 1;

	// Işının X ve Y eksenindeki yön vektörünü hesapla
	game->raycast->raydir_x = game->player->dir_x
		+ game->player->plane_x * game->raycast->camera_x;
	game->raycast->raydir_y = game->player->dir_y
		+ game->player->plane_y * game->raycast->camera_x;

	// Oyuncunun harita üzerindeki konumunu tamsayıya çevirerek belirle
	game->loc_px = (int)game->player->x;
	game->loc_py = (int)game->player->y;

	// X ve Y eksenindeki delta mesafelerini hesapla (1 birim ilerlemek için gereken mesafe)
	game->raycast->deltadist_x = fabs(1 / game->raycast->raydir_x);
	game->raycast->deltadist_y = fabs(1 / game->raycast->raydir_y);

	// Işının henüz duvara çarpıp çarpmadığını gösteren bayrağı sıfırla
	game->raycast->hit = 0;
}
