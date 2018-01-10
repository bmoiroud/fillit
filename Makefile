# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 17:53:22 by bmoiroud          #+#    #+#              #
#    Updated: 2016/12/03 15:09:45 by bmoiroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c  ft_list.c  ft_block.c  ft_map.c  ft_placement.c  ft_tools.c\

OBJS = main.o  ft_list.o  ft_block.o  ft_map.o  ft_placement.o  ft_tools.o\

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	@make -C ./libft
	gcc $(FLAGS) $(NAME) $(SRCS) $(LIB)

clean:
	@make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
