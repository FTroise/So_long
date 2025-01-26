# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:15:55 by ftroise           #+#    #+#              #
#    Updated: 2023/05/25 12:06:28 by ftroise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf.a

SRCS = printf_utils.c \
		ft_printf.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
