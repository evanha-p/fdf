# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:24:17 by evanha-p          #+#    #+#              #
#    Updated: 2022/10/06 15:39:45 by evanha-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -L /usr/local/lib -lmlx \
		 -I includes -framework OpenGL -framework AppKit -g
# Flags for compiling at home
# CFLAGS = -Wall -Wextra -Werror -L ./minilibx -lmlx -I ./minilibx \
				 -framework OpenGL -framework AppKit -g
NAME = fdf
C_F = srcs/
SRC = $(C_F)cleaner.c $(C_F)draw.c $(C_F)main.c $(C_F)utils.c \
	  $(C_F)modify.c $(C_F)reader.c $(C_F)errors.c $(C_F)events.c \
	  $(C_F)event_modifiers.c $(C_F)error_checkers.c \
	  $(C_F)draw_helper.c libft/libft.a
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
