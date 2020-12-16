# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2020/12/16 14:35:23 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Variables

PHONY			=	all clean fclean re

SOURCEFILES		=	format_utils.c	\
					ft_dprintf.c      \
					ft_lutoa_base.c   \
					ft_printf.c       \
					ft_vdprintf.c     \
					pad.c             \
					repr.c            \

OBJECTFILES		=	$(patsubst %.c,obj/%.o,$(SOURCEFILES))
	
HEADERS			=	header.h
	
CFLAGS			=	-Wall -Wextra -Werror

CC	  		  	= 	clang

NAME			=	libftprintf.a


#	Rules

all:			${NAME}

${NAME}:		${OBJECTFILES} ${HEADERS} libft/libft.a Makefile
				ar rcsT $@ ${OBJECTFILES} libft/libft.a

libft/libft.a:		
				make -C libft libft.a
				
obj/%.o:		%.c Makefile | obj
				${CC} ${CFLAGS} -c $< -o $@

obj:
				mkdir obj

clean:			
				rm -rf obj
				make -C libft fclean

fclean:			clean
				rm -rf ${NAME}

re:				fclean all

.PHONY:			${PHONY}	
