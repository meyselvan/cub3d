#include "../../INC/cub3d.h"

void	print_info(t_game *game) // Debugging
{
	printf("player       x %f\n", game->player->x);
	printf("player       y %f\n", game->player->y);
	printf("player   dir_x %f\n", game->player->dir_x);
	printf("player   dir_y %f\n", game->player->dir_y);
	printf("player plane_x %f\n", game->player->plane_x);
	printf("player plane_y %f\n", game->player->plane_y);
	printf("player   angle %f\n", game->player->angle);
	printf("\n");
	printf("raycast camera_x %f\n", game->raycast->camera_x);
	printf("perp_dist %f\n", game->raycast->perp_dist);
	printf("start_y   %d\n", game->raycast->start_y);
	printf("end_y     %d\n", game->raycast->end_y);
	printf("height    %d\n", game->raycast->height);
	printf("tex_x     %d\n", game->raycast->tex_x);
	printf("tex_y     %d\n", game->raycast->tex_y);
	printf("\n\n");
	printf("--------------------------\n");
}

int	exit_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	player_game(t_game *game)
{
	print_info(game);
	if (game->key->w)
		move_ws(game, 1);
	if (game->key->s)
		move_ws(game, -1);
	if (game->key->a)
		move_ad(game, -1);
	if (game->key->d)
		move_ad(game, 1);
	if (game->key->right)
		rotate_player(game, 1);
	if (game->key->left)
		rotate_player(game, -1);
}

int	game_hook(void *param)
{
    int		x;                // Ekranın yatay eksenindeki her piksel sütunu için sayaç
    t_game	*game;            // Oyun durumunu içeren yapı

    // parametreyi t_game yapısına dönüştür
    game = (t_game *)param;

    x = 0;                    // x ekseninde başlangıç değeri 0
    draw_floor_ceiling(game);  // Zemin ve tavanı çiz

    player_game(game);         // Oyuncu ile ilgili işlemleri yap (örneğin, hareketi hesapla)

    // Ekranın tüm genişliği boyunca her bir piksel sütununu işle
    while (x < SCREENWIDTH)
    {
        calc_ray(game, x);     // Işın izleme hesaplaması yap (her sütun için)
        dda(game);             // DDA algoritmasını kullanarak ışının duvarla nerede kesiştiğini bul
        calc_wall(game);       // Duvar yüksekliği ve görüntüsünü hesapla
        map_line(game, x);     // Hesaplanan sütunu ekrana çiz
        x++;                   // Bir sonraki sütuna geç
    }

    // Hesaplanan görüntüyü pencereye yerleştir (görüntüyü ekrana çiz)
    mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);

    // İşlevi başarılı bir şekilde tamamla (0 döndür)
    return (0);
}

