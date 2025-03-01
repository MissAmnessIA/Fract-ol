NAME				=	fractol

# Compiler and CFlags
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
LIBS      			=	-lXext -lX11 -lm
RM					=	rm -f

# Directories
LIBFT				=	./libft/libft.a
MLX					=	./minilibx-linux/libmlx.a
INC					=	inc/ libft/ minilibx-linux/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

# Source Files
SRC					=	$(SRC_DIR)fractol.c \
						$(SRC_DIR)utils.c \
						$(SRC_DIR)fractal_init.c \
						$(SRC_DIR)render.c \
						$(SRC_DIR)math_utils.c

OBJ 				= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 					$(MLX) $(LIBFT) $(NAME)

$(NAME): 				$(OBJ) $(MLX) $(LIBFT)
						@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

$(LIBFT):
						@make -sC ./libft

$(MLX):
						@make -sC ./minilibx-linux

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C ./minilibx-linux
						@make clean -C ./libft

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) $(MLX)
						@$(RM) $(LIBFT)

re: 					fclean all

.PHONY: 				all clean fclean re