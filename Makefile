.PHONY:     			all $(NAME) clear mkbuild lib minilibx clean fclean re norm

GREEN					= \033[1;32m
END						= \033[0m

NAME					= so_long

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= so_long.h

DIR						= src/
SRC			 			= main.c \
							array.c \
							check_map.c \
							close.c \
							coord.c \
							count.c \
							errors.c \
							images.c \
							init.c \
							moves.c \
							path_finding_utils.c \
							path_finding_c.c \
							path_finding_e.c \
							so_long_utils.c \
							
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
							@echo "$(GREEN)[SO_LONG IS READY] $(END)"
							
mkbuild:
							@mkdir -p build

clear:
							$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT) libft
							@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) ft_printf/libftprintf.a get_next_line/gnl.a $(LINUX) -g
							
lib:
							@make -C $(LIB_DIR)
							@echo "$(GREEN)[LIBFT OK] $(END)"
							@make -C ft_printf/
							@echo "$(GREEN)[FT_PRINTF OK] $(END)"
							@make -C get_next_line/
							@echo "$(GREEN)[GNL OK] $(END)"


minilibx:
							@make -C $(MINILIB_DIR)
						
clean:					
							@${RM} $(OBJECTS)
							@make clean -C $(LIB_DIR)  
							@make clean -C $(MINILIB_DIR) 
							@make clean -C ft_printf/ 
							@make clean -C get_next_line/ 
							@${RM} $(BUILD_DIR)
							@echo "$(GREEN)[CLEAN DONE]$(END)"

fclean:					clean
							@${RM} ${NAME}
							@make fclean -C $(LIB_DIR) 
							@make fclean -C ft_printf/ 
							@make fclean -C get_next_line/ 
							@echo "$(GREEN)[FCLEAN DONE]$(END)"

norm:
							@norminette $(DIR)
							@norminette $(HEADER_DIR)/$(HEADER_FILE) 
							@echo "$(GREEN)-----------------------------------------$(END)"
							@norminette $(LIB_DIR) 
							@echo "$(GREEN)-----------------------------------------$(END)"
							@norminette ft_printf/ 
							@echo "$(GREEN)-----------------------------------------$(END)"
							@norminette get_next_line/
							@echo "$(GREEN)-----------------------------------------$(END)"

re:						fclean all
							$(MAKE) all
							@echo "$(GREEN)[REMAKE DONE] $(END)"
