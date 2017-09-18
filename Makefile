# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlouar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 15:40:57 by hlouar            #+#    #+#              #
#    Updated: 2016/03/18 18:06:05 by hlouar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/main.c src/init.c src/shortcut.c src/fractal.c src/changecolor.c \

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = src/libft/libft.a

FLAGMLX = -lmlx -framework Opengl -framework AppKit

$(NAME):$(OBJ)
		@cd src/libft && make re && cd ..
		@gcc $(FLAG) -o $(NAME) $(FLAGMLX) $(SRC) $(LIBS) -I.

all: $(NAME)

clean:
		@cd src/libft && make clean && cd ..
		@/bin/rm -f $(OBJ)

fclean: clean
	@cd src/libft && make fclean && cd ..
	@/bin/rm -f $(NAME)

re:	fclean all
