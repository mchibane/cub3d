# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:18:04 by mchibane          #+#    #+#              #
#    Updated: 2022/01/28 14:48:48 by mchibane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c \
				ft_atol.c\
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_ischarset.c\
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c\
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_uitoa.c \
				ft_uitoa_base.c \
				ft_uitoa_ptr.c \
				get_next_line.c \
				ft_strequal.c\

OBJS_DIR	=	objs/

OBJS		=	$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})

NAME		=	libft.a

CC			=	gcc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(OBJS_DIR)%.o:	%.c
				mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS_DIR}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
