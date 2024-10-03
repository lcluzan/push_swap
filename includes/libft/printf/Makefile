# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:35:02 by lcluzan           #+#    #+#              #
#    Updated: 2024/07/22 14:14:33 by lcluzan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_print_character.c ft_print_decimal_integer.c \
 ft_print_hex.c ft_print_ptr.c ft_print_str.c ft_print_unsigned_decimal.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: 	 ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
