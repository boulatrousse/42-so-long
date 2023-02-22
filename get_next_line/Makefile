# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:03:43 by lboulatr          #+#    #+#              #
#    Updated: 2023/02/22 16:14:50 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					= get_next_line.c \
							get_next_line_utils.c \

OBJS    				=   ${SRCS:.c=.o}

CC						=	gcc

FLAGS    				=   -Wall -Wextra -Werror

HEADER    				=   get_next_line.h

LIB        				=   ar rc

RM        				=   rm -f

NAME    				=   gnl.a

all:        			${NAME}

%.o:        			%.c ${HEADER}
							${CC} ${FLAGS} -include ${HEADER} -c $< -o $@

${NAME}:    			${OBJS} ${HEADER}
								${LIB} ${NAME} ${OBJS}

bonus:        			${OBJS}
								${LIB} ${NAME} ${OBJS}

clean:
							${RM} ${OBJS}

fclean:        			clean
							${RM} ${NAME}

re:            			fclean all

.PHONY: all clean fclean re