# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 10:41:43 by bepinhei          #+#    #+#              #
#    Updated: 2024/08/12 10:44:49 by bepinhei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_printf.c ft_putptr.c ft_putnbr_hex.c ft_putnbr_char.c ft_putnbr.c \
			ft_putstr.c  ft_putchar.c \
			
OBJS =  $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all