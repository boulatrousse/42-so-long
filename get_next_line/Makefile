# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:03:43 by lboulatr          #+#    #+#              #
#    Updated: 2023/02/23 14:39:47 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					= 	get_next_line.c \
							get_next_line_utils.c \

OBJS    				=   ${SRCS:%.c=$(BUILD)%.o}

BUILD 					= 	build/

CC						=	gcc

FLAGS    				=   -Wall -Wextra -Werror

HEADER    				=   get_next_line.h

LIB        				=   ar rc

RM        				=   rm -rf

NAME    				=   gnl.a

all:        			${NAME}

$(BUILD)%.o:        	%.c ${HEADER}
							@mkdir -p $(@D)
							${CC} ${FLAGS} -include ${HEADER} -c $< -o $@

${NAME}:    			${OBJS} ${HEADER}
							${LIB} ${NAME} ${OBJS}

clean:
							${RM} ${OBJS}
							$(RM) $(BUILD)

fclean:        			clean
							${RM} ${NAME}

re:            			fclean all

.PHONY: all clean fclean re