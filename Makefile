# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 08:11:14 by haghouli          #+#    #+#              #
#    Updated: 2023/01/11 05:33:34 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX		= -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
MLX_B 	= -I /usr/local/include ./bonus_main.c -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

FILES = ./utiles/gnl/get_next_line.c \
		./utiles/gnl/get_next_line_utils.c \
		./utiles/ft_split.c \
		./utiles/map_conf.c \
		./utiles/create_map.c \
		./utiles/moves.c \
		./utiles/ft_itoa.c \
		./utiles/check_stuck.c \
		./utiles/counters.c \
		./utiles/read_file.c \
		./utiles/get_start_dim.c \
		./utiles/ft_exit.c \
		./utiles/check_nl.c \
		./utiles/check_extention.c \

B_FILES = ./bonus/animations.c\
		./bonus/create_map_bonus.c \
		./bonus/moves_bonus.c \
		./bonus/check_elements_bonus.c \
		./bonus/check_enemy_near.c \
		./bonus/ft_lstnew_bonus.c \
		./bonus/ft_lstadd_back_bonus.c \
		./bonus/get_enemies_location.c \

OBJS = $(FILES:.c=.o)
B_OBJS = $(B_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(OBJS) ./ft_printf/libftprintf.a $(MLX) -o $(NAME)

bonus : $(OBJS) $(B_OBJS)
	$(CC)  $(OBJS) $(B_OBJS) ./ft_printf/libftprintf.a $(MLX_B) -o  $(NAME)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@