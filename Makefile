CC      = cc
NAME    = cub3D
CFLAGS  = -g -Wall -Werror -Wextra
MLXFLAG	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./SRC/
OBJ_DIR = ./OBJ/
INC_DIR = ./INC
MLX_DIR = ./MLX/
FT_DIR  = ./LIBFT/

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC = $(SRC_FILES)
OBJ = $(OBJ_FILES)

LIBFT = ./LIBFT/libft.a
MLX   = ./MLX/libmlx.a

FTSRC = $(shell ls ./libft/*.c)

all: dep
	$(MAKE) $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@

dep: $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR) 2> /dev/null

$(MLX_DIR):
	mkdir -p $(MLX_DIR)
	curl -O https://cdn.intra.42.fr/document/document/18344/minilibx_opengl.tgz
	tar -xvf minilibx_opengl.tgz -C $(MLX_DIR) --strip-components=1
	rm -fr minilibx_opengl.tgz 

$(LIBFT): $(FTSRC)
	make -C $(FT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(FT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(FT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re dep