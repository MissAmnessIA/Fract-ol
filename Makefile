NAME				=	fractol

# Compiler and CFlags
CC					=	cc
CFLAGS				=	-Wall  -Wextra
LIBS      			=	-lXext -lX11 -lm
RM					=	rm -f

# Directories
MLX					=	./minilibx-linux/libmlx.a
INC					=	inc/ libft/ minilibx-linux/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

# Source Files
SRC					=	$(SRC_DIR)main.c \
						$(SRC_DIR)init.c \
						$(SRC_DIR)events.c \
						$(SRC_DIR)math_utils.c \
						$(SRC_DIR)render.c \
						$(SRC_DIR)string_utils.c



OBJ 				= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 					$(MLX) $(LIBFT) $(NAME)

$(NAME): 				$(OBJ) $(MLX) $(LIBFT)
						@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

$(MLX):
						@make -sC ./minilibx-linux

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C ./minilibx-linux

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) $(MLX)

re: 					fclean all

.PHONY: 				all clean fclean re