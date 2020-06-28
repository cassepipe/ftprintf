# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2020/06/27 16:27:53 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################


SRC			=	$(wildcard *.c)	

OBJS		= 	${SRC:.c=.o}
	
CFLAGS		=	-Wall -Wextra 

RM			= 	rm -rf

CC			= 	gcc


#	Rules

all:			libftprintf.a

a.out:			${OBJS} libft/libft.a
				${CC} ${OBJS} libft/libft.a

libftprintf.a:	${OBJS} libft/libft.a 
				ar rcs $@ ${OBJS} $(wildcard libft/*.o)

%.o:			%.c	header.h
				${CC} ${CFLAGS} -c $< -o $@

libft/libft.a:
				$(MAKE) -C libft

clean:			
				${RM} ${OBJS}

fclean:			clean
				rm -f a.out libftprintf.a

re:				fclean all

.PHONY:			all clean fclean re 
