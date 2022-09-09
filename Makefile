# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:24:17 by evanha-p          #+#    #+#              #
#    Updated: 2022/09/09 14:22:00 by evanha-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -L /usr/local/lib -lmlx -I /minilibx/ \
		 -framework OpenGL -framework AppKit -g
# Flags for compiling at home
# CFLAGS = -Wall -Wextra -Werror -L ./minilibx -lmlx -I ./minilibx \
				 -framework OpenGL -framework AppKit -g
NAME = fdf
SRC = draw.c main.c utils.c  modify.c reader.c errors.c libft/libft.a
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
