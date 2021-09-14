# **************************************************************************** #
#                                                                              #
#                                                           :::      ::::::::  #
#  Makefile                                               :+:      :+:    :+:  #
#                                                       +:+ +:+         +:+    #
#  By: zcanales <zcanales@student.42urduliz.com>      +#+  +:+       +#+       #
#                                                   +#+#+#+#+#+   +#+          #
#  Created: 2021/07/22 12:11:18 by zcanales              #+#    #+#            #
#  Updated: 2021/08/02 11:21:53 by zcanales             ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c\
		ft_printf_utils.c\

OBJS =	$(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
INCLUDES = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	make -C Libft
	cp Libft/libft.a .
	mv libft.a $(NAME) 	
	$(AR) $(NAME) $(OBJS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $(SRC) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY : all clean fclean re 
