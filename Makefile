# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2020/12/12 22:40:44 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################


SRC			=	$(wildcard *.c)	

OBJS		= 	${SRC:.c=.o}
	
CFLAGS		=	-Wall -Wextra -fsanitize=address -g3

RM			= 	rm -f

CC			= 	 clang


#	Rules

all:			libftprintf.a a.out

a.out:			${OBJS} libft/libft.a Makefile
				${CC} ${OBJS} libft/libft.a

libftprintf.a:	${OBJS} libft/libft.a  
				ar rcs $@ ${OBJS} $(wildcard libft/*.o)
				make -C pft

%.o:			%.c	header.h
				${CC} ${CFLAGS} -c $< -o $@

libft/libft.a:
				$(MAKE) -C libft

clean:			
				${RM} ${OBJS}
				make -C libft clean

fclean:			clean
				rm -f a.out libftprintf.a
				rm -f libft/libft.a

re:				fclean all

.PHONY:			all clean fclean re 
