# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 19:43:41 by pmartine          #+#    #+#              #
#    Updated: 2016/04/15 19:00:19 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/coord.c src/hook.c src/mlx_color.c src/vect_crux.c src/vect_octant.c src/draw.c src/main.c src/vect_ab.c src/vect_octant2.c

FLAGS = -Wall -Werror -Wextra

$(NAME):
	make -C libft/ re
	make -C minilibx_macos/ re
	gcc $(CFLAGS) -o $(NAME) $(SRC) -I libft/includes/libft.h \
	-lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "Program created"
all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	make -C minilibx_macos/ clean
	make -C libft/ fclean
	@echo "all files removed"

re: fclean all

.PHONY : all clean fclean re
