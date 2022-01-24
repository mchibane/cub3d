# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 13:34:08 by mchibane          #+#    #+#              #
#    Updated: 2021/11/23 14:46:30 by mchibane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft.a

SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
HEAD_DIR	=	include/
LIBFT_DIR	=	libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ${HEAD_DIR} -I ${LIBFT_DIR}
RM			=	rm -rf

SRCS		=	ft_printf.c \
				format_handler.c \
				parse_format.c \
				padding_handler.c \
				precision_handler.c \
				print_format.c \
				print_string.c \
				print_percent.c \
				print_char.c \
				print_int.c \
				print_uint.c \
				print_uint_hex.c \
				print_uint_ptr.c \

OBJS		=	$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})

.c.o:
				${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:			${NAME}

$(NAME):		${OBJS}
				make -C ${LIBFT_DIR}
				cp ${LIBFT_DIR}${LIBFT} ${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:
				make fclean -C ${LIBFT_DIR}
				${RM} ${OBJS_DIR}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
