# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:03:43 by lboulatr          #+#    #+#              #
#    Updated: 2023/01/23 14:43:55 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c \
			get_next_line_utils.c \

OBJS    =    ${SRCS:.c=.o}

CC		=	gcc

FLAGS    =    -Wall -Wextra -Werror

HEADER    =    get_next_line/

LIB        =    ar rc

RM        =    rm -f

NAME    =    gnl.a

all:        ${NAME} Makefile

%.o:        %.c ${HEADER} Makefile
			${CC} ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:    ${OBJS}
			${LIB} ${NAME} ${OBJS}

bonus:        ${B_OBJS} ${OBJS}
			${LIB} ${NAME} ${OBJS} ${B_OBJS}

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:        clean
			${RM} ${NAME}

re:            fclean all

.PHONY: all clean fclean re bonus