# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:23 by ybouzafo          #+#    #+#              #
#    Updated: 2023/12/08 11:09:18 by looutbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub
CC=cc
CFLAGS=#-Wall -Wextra -Werror
CFLAGS+=-fsanitize=address
RM=rm -f
SRC =  cub.c  get_line.c ./libft/ft_split.c ./libft/ft_strdup.c ./libft/ft_atoi.c  ./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strlen.c \
		ft_strncmp.c check_map.c check_walls.c check_wall.c check_m.c check_ma.c check_space.c ./ray_casting/map_2d.c ./ray_casting/movement.c ./ray_casting/player.c\
		./ray_casting/rays.c ./ray_casting/3D.c
	


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -lmlx -framework OpenGl  -framework Appkit -o $(NAME)
 	#main.c -lmlx -framework OpenGL -framework AppKit
clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all
