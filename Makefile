NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS		=	ft_printf.c \
			ft_print1.c 
			
OBJS		=	$(SRCS:.c=.o)

%.o:	%.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
fclean:	clean 
		$(RM) $(NAME)
re:		fclean all

.PHONY: all clean fclean re
