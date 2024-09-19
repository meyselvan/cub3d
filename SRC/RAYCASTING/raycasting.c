#include "../../INC/cub3d.h"

void	calc_side(t_game *game)
{
    // Eğer ışının x yönündeki bileşeni negatifse (sola doğru gidiyorsa)
	if (game->raycast->raydir_x < 0)
	{
        // X ekseninde adım büyüklüğünü -1 yap (sola doğru)
		game->raycast->step_x = -1;

        // X ekseninde ışının ilk duvara kadar olan mesafesini hesapla
		game->raycast->sidedist_x = (game->player->x - game->loc_px) \
			* game->raycast->deltadist_x;
	}
	else // Işının x yönündeki bileşeni pozitifse (sağa doğru gidiyorsa)
	{
        // X ekseninde adım büyüklüğünü 1 yap (sağa doğru)
		game->raycast->step_x = 1;

        // X ekseninde ışının ilk duvara kadar olan mesafesini hesapla
		game->raycast->sidedist_x = (game->loc_px + 1.0 - game->player->x) \
			* game->raycast->deltadist_x;
	}

    // Eğer ışının y yönündeki bileşeni negatifse (aşağıya doğru gidiyorsa)
	if (game->raycast->raydir_y < 0)
	{
        // Y ekseninde adım büyüklüğünü -1 yap (aşağıya doğru)
		game->raycast->step_y = -1;

        // Y ekseninde ışının ilk duvara kadar olan mesafesini hesapla
		game->raycast->sidedist_y = (game->player->y - game->loc_py) \
			* game->raycast->deltadist_y;
	}
	else // Işının y yönündeki bileşeni pozitifse (yukarıya doğru gidiyorsa)
	{
        // Y ekseninde adım büyüklüğünü 1 yap (yukarıya doğru)
		game->raycast->step_y = 1;

        // Y ekseninde ışının ilk duvara kadar olan mesafesini hesapla
		game->raycast->sidedist_y = (game->loc_py + 1.0 - game->player->y) \
			* game->raycast->deltadist_y;
	}
}


void	calc_ray(t_game *game, int x)
{
	init_raycast(game, x);
	calc_side(game);
}

void dda(t_game *game)
{
    // Raycasting işlemi sırasında duvara çarpana kadar döngü devam eder
    while (game->raycast->hit == 0)
    {
        // X ekseninde adım mesafesi daha küçükse
        if (game->raycast->sidedist_x < game->raycast->sidedist_y)
        {
            // X eksenindeki mesafeyi deltadist_x kadar artır
            game->raycast->sidedist_x += game->raycast->deltadist_x;
            // X koordinatını step_x'e göre güncelle
            game->loc_px += game->raycast->step_x;
            // X yönünde mi gidildiğini kontrol et ve side1 değerini ayarla
            if (game->raycast->step_x == 1)
                game->raycast->side1 = 1;  // Pozitif X yönü
            else
                game->raycast->side1 = 0;  // Negatif X yönü
        }
        // Y ekseninde adım mesafesi daha küçükse
        else
        {
            // Y eksenindeki mesafeyi deltadist_y kadar artır
            game->raycast->sidedist_y += game->raycast->deltadist_y;
            // Y koordinatını step_y'e göre güncelle
            game->loc_py += game->raycast->step_y;
            // Y yönünde mi gidildiğini kontrol et ve side1 değerini ayarla
            if (game->raycast->step_y == 1)
                game->raycast->side1 = 2;  // Pozitif Y yönü
            else
                game->raycast->side1 = 3;  // Negatif Y yönü
        }
        // Haritada duvara çarpıldı mı kontrol et ('1' karakteri duvarı temsil ediyor)
        if (game->map[game->loc_py][game->loc_px] == '1')
            game->raycast->hit = 1;  // Duvara çarpıldı, döngü sona erer
    }
}
