# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:04:16 by ahussein          #+#    #+#              #
#    Updated: 2022/07/26 17:04:35 by ahussein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

OBJS =	${SRC:.c=.o}

RM	=	rm -f

LIB =	ar -rcs

GCCF = 	gcc -Wall -Wextra -Werror


SRC =	ft_printf.c ft_printf_uses.c ft_printhex.c ft_printnumbers.c\
		ft_printu_numbers.c ft_printptr.c


.c.o:
		${GCCF} -c $< -o ${<:.c=.o}
		@echo "${COLOUR_GREEN}Compiled!${COLOUR_END}"



COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[1;33m

${NAME} :	${OBJS}
		@${LIB} ${NAME} ${OBJS}

all :	${NAME}


clean :
		@${RM} ${OBJS}
		@echo "$(COLOUR_RED)object files cleaned !!$(COLOUR_END)"


fclean :	clean
		@${RM} ${NAME}
		@echo "$(COLOUR_BLUE)executable files cleaned successfully!$(COLOUR_END)"

re :	fclean all
		@echo "$(COLOUR_YELLOW) Program restarted!$(COLOUR_END)"