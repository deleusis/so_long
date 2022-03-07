# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 18:02:42 by deleusis          #+#    #+#              #
#    Updated: 2022/03/03 18:03:54 by deleusis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIST = so_long.c read_map.c \
		get_next_line.c get_next_line_utils.c \
		init_image.c check_all_map.c check_all_map2.c move_player.c \
		move_enemy.c utils.c utils2.c \
		

OBJ =  $(patsubst %.c,%.o,$(LIST))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC)  -Imlx -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
