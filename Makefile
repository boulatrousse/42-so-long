.PHONY:     			all $(NAME) clear mkbuild lib minilibx clean fclean re

PURPLE					= \033[1;35m
END						= \033[0m

NAME					= so_long

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= so_long.h

DIR						= src/
SRC			 			= main.c \
							array.c \
							check_map.c \
							moves.c \
							path_finding_c_utils.c \
							path_finding_c.c \
							path_finding_e.c \
							so_long_utils.c \
							so_long_utils_2.c \
							images.c \
							init.c \
							coord.c \
							errors.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

$(BUILD_DIR)%.o:		$(DIR)%.c $(LIB_DIR) $(HEADER_DIR)/$(HEADER_FILE)
							@mkdir -p $(@D)
							$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@ -g

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
							@echo "$(PURPLE)[SO_LONG IS READY] $(END)"
							
mkbuild:
							@mkdir -p build

clear:
							$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT) libft
							@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) ft_printf/libftprintf.a get_next_line/gnl.a $(LINUX) -g
							
lib:
							@make -C $(LIB_DIR)
							@echo "$(PURPLE)[LIBFT OK] $(END)"
							@make -C ft_printf/
							@echo "$(PURPLE)[FT_PRINTF OK] $(END)"
							@make -C get_next_line/
							@echo "$(PURPLE)[GNL OK] $(END)"


minilibx:
							@make -C $(MINILIB_DIR)
						
clean:					
							@${RM} $(OBJECTS)
							@make clean -C $(LIB_DIR)  
							@make clean -C $(MINILIB_DIR) 
							@make clean -C ft_printf/ 
							@make clean -C get_next_line/ 
							@${RM} $(BUILD_DIR)
							@echo "$(PURPLE)[CLEAN DONE]$(END)"

fclean:					clean
							@${RM} ${NAME}
							@make fclean -C $(LIB_DIR) 
							@make fclean -C ft_printf/ 
							@make fclean -C get_next_line/ 
							@echo "$(PURPLE)[FCLEAN DONE]$(END)"

re:						fclean all
							$(MAKE) all
							@echo "$(PURPLE)[REMAKE DONE] $(END)"
