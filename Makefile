NAME				=	cub3D
LIBFT				=	libftprintf.a
MLX					=	libmlx.a

SRCS_DIR			=	srcs/
OBJS_DIR			=	objs/
HEAD_DIR			=	include/
LIBFT_DIR			=	libft/
MLX_DIR				=	mlx/

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -g #-fsanitize=address
INC					=	-I$(HEAD_DIR) -I$(LIBFT_DIR)$(HEAD_DIR) -I$(LIBFT_DIR)$(LIBFT_DIR) -I$(MLX_DIR)
DEPENDENCIES		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
RM					=	rm -rf

HEADER				=	$(HEAD_DIR)cub3d.h

SRCS				=	check_map.c\
						cub3d.c\
						draw_utils.c\
						draw.c\
						exit.c\
						free.c\
						init.c\
						input.c\
						main.c\
						map_fill.c\
						map_parsing.c\
						parsing.c\
						raycasting.c\
						rc_init.c\
						rc_update.c\
						rc_utils.c\
						set_colors.c\
						set_textures.c\
						utils.c\

OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c $(HEADER)
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS) $(HEADER)
					@echo "Compiling libft ..."
					@make -s -C $(LIBFT_DIR)
					@echo "Libft built !"
					@echo "Compiling MLX ..."
					@make -s -C $(MLX_DIR)
					@echo "MLX built !"
					$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(DEPENDENCIES) -o $(NAME)

clean:
					make fclean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re



