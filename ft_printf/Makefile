# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:28:05 by haghouli          #+#    #+#              #
#    Updated: 2022/10/31 18:28:10 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= ft_put_base16_upper.c \
		ft_put_base16_lower.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_putunbr.c \
		ft_count_base.c \
		ft_count_Ubase.c

SRC_O 	= $(SRC:.c=.o) 

NAME 	= libftprintf.a
CC		= cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC_O)
	ar -rc $(NAME)  $(SRC_O)

clean :
	rm -f $(SRC_O)

fclean : clean 
	rm -f $(NAME)

re : clean all
