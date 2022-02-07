NAME				=	cub3D
B_NAME				=	cub3D_bonus
LIBFT				=	libftprintf.a
MLX					=	libmlx.a

SRCS_DIR			=	srcs/
OBJS_DIR			=	objs/
HEAD_DIR			=	include/
LIBFT_DIR			=	libft/
MLX_DIR				=	mlx/
BONUS_DIR			=	bonus/
B_OBJS_DIR			=	$(BONUS_DIR)objs/

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -g #-fsanitize=address
INC					=	-I$(HEAD_DIR) -I$(LIBFT_DIR)$(HEAD_DIR) -I$(LIBFT_DIR)$(LIBFT_DIR) -I$(MLX_DIR)
DEPENDENCIES		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
RM					=	rm -rf

HEADER				=	$(HEAD_DIR)cub3d.h
B_HEAD				=	$(HEAD_DIR)bonus.h

SRCS				=	check_map.c\
						cub3d.c\
						draw_utils.c\
						draw.c\
						exit.c\
						free.c\
						hooks.c\
						init.c\
						input.c\
						keys.c\
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

B_SRCS				=	check_map_bonus.c\
						cub3d_bonus.c\
						draw_utils_bonus.c\
						draw_bonus.c\
						exit_bonus.c\
						free_bonus.c\
						hooks_bonus.c\
						init_bonus.c\
						input_bonus.c\
						input2_bonus.c\
						keys_bonus.c\
						main_bonus.c\
						map_fill_bonus.c\
						map_parsing_bonus.c\
						minimap_bonus.c\
						parsing_bonus.c\
						raycasting_bonus.c\
						rc_init_bonus.c\
						rc_update_bonus.c\
						rc_utils_bonus.c\
						set_colors_bonus.c\
						set_textures_bonus.c\
						utils_bonus.c\

OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
B_OBJS				=	$(addprefix $(B_OBJS_DIR), $(B_SRCS:.c=.o))

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c $(HEADER)
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(B_OBJS_DIR)%.o:	$(BONUS_DIR)%.c $(HEADER) $(B_HEAD)
					@mkdir -p $(B_OBJS_DIR)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:				$(NAME)
bonus:				$(B_NAME)

$(NAME):			$(OBJS) $(HEADER)
					@echo "Compiling libft ..."
					@make -s -C $(LIBFT_DIR)
					@echo "Libft built !"
					@echo "Compiling MLX ..."
					@make -s -C $(MLX_DIR)
					@echo "MLX built !"
					$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(DEPENDENCIES) -o $(NAME)

$(B_NAME):			$(B_OBJS) $(HEADER) $(B_HEAD)
					@echo "Compiling libft ..."
					@make -s -C $(LIBFT_DIR)
					@echo "Libft built !"
					@echo "Compiling MLX ..."
					@make -s -C $(MLX_DIR)
					@echo "MLX built !"
					$(CC) $(CFLAGS) $(INC) $(B_OBJS) $(LIBFT_DIR)$(LIBFT) $(DEPENDENCIES) -o $(B_NAME)

clean:
					make fclean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(OBJS_DIR)
					$(RM) $(B_OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)
					$(RM) $(B_NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus



