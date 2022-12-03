#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 02:02:13 by tsedigi           #+#    #+#              #
#    Updated: 2015/03/29 21:56:07 by tsedigi          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_check_options.c ft_list_dir.c get_files.c ft_listdir.c ft_display.c ft_setting.c ft_get_arglist.c ft_recurse.c ft_sort_ar.c ft_sort_rt.c ft_bonus.c ft_display_l.c tools.c ft_sorting2.c ft_freellist.c ft_finalrainbow.c leaks_out.c display_col.c

OBJ = $(SRC:.c=.o)

NAME = ft_ls


FLAGS = -Wall -Wextra

CC = gcc


all: lib $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -I libft/ libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

re: relib fclean all 

clean:
	rm -f $(OBJ)

fclean: clean libclean
	rm -f $(NAME)

lib:
	make -C libft

relib:
	make -C libft re

libclean:
	make -C libft fclean
