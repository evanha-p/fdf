# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:24:17 by evanha-p          #+#    #+#              #
#    Updated: 2022/07/19 16:57:22 by evanha-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -L /usr/local/lib -lmlx -I /minilibx/ \
		 -framework OpenGL -framework AppKit -g
NAME = fdf
SRC = draw.c main.c read.c utils.c errors.c libft/libft.a
OBJ = $(patsubst %.c, %.o, $(SRC))
LIBFT = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
