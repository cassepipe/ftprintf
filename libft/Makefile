# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2020/12/18 15:53:57 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Variables

PHONY			=	all clean fclean re

SOURCEFILES		=	ft_atoi.c			\
					ft_bzero.c          \
					ft_calloc.c         \
					ft_isalnum.c        \
					ft_isalpha.c        \
					ft_isascii.c        \
					ft_isdigit.c        \
					ft_isprint.c        \
					ft_itoa.c           \
					ft_lstadd_back.c    \
					ft_lstadd_front.c   \
					ft_lstclear.c       \
					ft_lstdelone.c      \
					ft_lstiter.c        \
					ft_lstlast.c        \
					ft_lstmap.c         \
					ft_lstnew.c         \
					ft_lstsize.c        \
					ft_memccpy.c        \
					ft_memchr.c         \
					ft_memcmp.c         \
					ft_memcpy.c         \
					ft_memmove.c        \
					ft_memset.c         \
					ft_putchar_fd.c     \
					ft_putendl_fd.c     \
					ft_putnbr_fd.c      \
					ft_putstr_fd.c      \
					ft_split.c          \
					ft_strchr.c         \
					ft_strdup.c         \
					ft_strjoin.c        \
					ft_strlcat.c        \
					ft_strlcpy.c        \
					ft_strlen.c         \
					ft_strmapi.c        \
					ft_strncmp.c        \
					ft_strndup.c        \
					ft_strnstr.c        \
					ft_strrchr.c        \
					ft_strtrim.c        \
					ft_substr.c         \
					ft_tolower.c        \
					ft_toupper.c        \

OBJECTFILES		=	$(patsubst %.c,obj/%.o,$(SOURCEFILES))
	
HEADERS			=	libft.h
	
CFLAGS			=	-Wall -Wextra -Werror

CC	  		  	= 	clang

NAME			=	libft.a


#	Rules

all:			${NAME}

${NAME}:		${OBJECTFILES} ${HEADERS} Makefile
				ar rcs $@ ${OBJECTFILES}

obj/%.o:		%.c | obj
				${CC} ${CFLAGS} -c $< -o $@

obj:
				mkdir obj

clean:			
				rm -rf obj

fclean:			clean
				rm -rf ${NAME}

re:				fclean all

.PHONY:			${PHONY}	
