# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:54:04 by lboulatr          #+#    #+#              #
#    Updated: 2023/02/20 14:04:53 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 						= ft_printf.c count.c ft_hexa.c ft_putchar_fd_count.c ft_putnbr_fd_count.c ft_putnbr_fd_usign.c \
								ft_putstr_fd_count.c ft_hexaptr.c
	
OBJS 						= ${SRCS:.c=.o}

CC 							= cc

FLAGS 						= -Wall -Werror -Werror

HEADERS 					= ft_printf/

NAME 						= libftprintf.a

LIB 						= ar rc

RM 							= rm -f

%.o:						%.c ${HEADERS} Makefile
								${CC} ${FLAGS} -I${HEADERS} -c $< -o $@  
	
all:						${NAME} Makefile libft

libft:
								@make -C libft

${NAME}:					libft ${OBJS} Makefile
								cp libft/libft.a ./${NAME}
								${LIB} ${NAME} ${OBJS}

clean:	
								${RM} ${OBJS}
								make clean -C libft

fclean:						clean
								${RM} ${NAME}
								make fclean -C libft

re:							fclean all

.PHONY:	all clean fclean re libft
