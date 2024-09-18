CC      = cc
NAME    = cub3d
CFLAGS  = -g -Wall -Werror -Wextra

SRC_DIR = ./SRC/
OBJ_DIR = ./OBJ/
INC_DIR = ./include

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


SRC = $(SRC_FILES)
OBJ = $(OBJ_FILES)

LIBFT = ./libft/libft.a
FTDIR = libft
FTSRC = $(shell ls ./libft/*.c)

all: $(NAME)

# Programı oluştur
$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ) 
	make -C ./MLX/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

# Libft'i oluştur
$(LIBFT): $(FTSRC)
	make -C libft

# Obj dosyalarını oluştur
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@) # Eğer dizin yoksa oluştur
	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

# Obj dizinini oluştur
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C libft/
	make clean -C MLX/
	rm -rf $(OBJ_DIR)

fclean: clean
	make clean -C MLX/
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
