# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 13:58:18 by ybouzafo          #+#    #+#              #
#    Updated: 2023/11/01 17:36:49 by looutbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
RM=rm -f
SRC =  ft_substr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_split.c ft_atoi.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
