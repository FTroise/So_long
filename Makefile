# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:59:55 by ftroise           #+#    #+#              #
#    Updated: 2023/06/08 23:41:16 by ftroise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft2
LIBFT			=	$(LIBFT_PATH)
FT_PRINTF_PATH	=	./ft_printf
FT_PRINTF		=	$(FT_PRINTF_PATH)

SOURCES_FILES	=	main.c check_things.c checkmap.c draw_map.c enemy_mv.c \
					game_set.c image_settings.c keys.c movement.c \
					readmap.c animation.c\
					./player_settings/player_mv_settings_up.c \
					./player_settings/player_mv_settings_down.c \
					./player_settings/player_mv_settings_left.c \
					./player_settings/player_mv_settings_right.c \

HEADER			=	./so_long.h

OBJECTS			=	$(SOURCES_FILES:.c=.o)

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib


CFLAGS			=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				make -C $(FT_PRINTF_PATH)
				make -C $(LIBFT_PATH)
				$(CC) $(OBJECTS) $(LIBFT)/libft.a $(FT_PRINTF)/ftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${FT_PRINTF_PATH}



fclean:			clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(FT_PRINTF_PATH)
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean re
