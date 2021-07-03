# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sverkart <sverkart@msk.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 14:50:30 by sverkart          #+#    #+#              #
#    Updated: 2020/10/27 15:42:20 by sverkart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SC = ./srcs/

CC = gcc -Wall -Werror -Wextra

CFAG = -framework OpenGL -framework Appkit

LIBFT = ./libft

SRCS = $(SC)main.c\
	$(SC)print_error.c\
	$(SC)gnl.c\
	$(SC)bmp.c\
	$(SC)utils.c\
	$(SC)finish.c\
	$(SC)first.c\
	$(SC)parser.c\
	$(SC)second.c\
	$(SC)textur.c\
	$(SC)add.c\
	$(SC)map.c\
	$(SC)wall.c\
	$(SC)keybrd.c\
	$(SC)raycst.c\
	$(SC)key_fc.c\
	$(SC)pars.c\
	$(SC)rct.c\
	$(SC)text_end.c\
	$(SC)txtr_er.c\
	$(SC)txtr_er2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus
	@cd minilibx && $(MAKE)
	@$(CC) $(SRCS) minilibx/libmlx.a libft/libft.a -o $(NAME) $(CFAG)
	@echo "\033[32mCompilation: OK\033[0m" 

clean:
	@$(MAKE) -C $(LIBFT) clean
	@rm -f $(OBJS)
	@echo "\033[32mDeletion: OK\033[0m" 

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re