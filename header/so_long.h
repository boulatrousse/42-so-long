/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:16:45 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 16:47:31 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/include/libft.h"
# include "../minilibx_linux/mlx.h"

//--------------------- STRUCT ----------------------

typedef struct s_char
{
	int		ct_e;
	int		ct_p;
	int		ct_c;
	int		x_col;
	int		y_col;
}	t_char;

typedef struct s_col
{
	int		count;
	int		x;
	int		y;
	int		x_perso;
	int		y_perso;
}	t_col;

typedef struct s_game
{
	int		lines;
	int		rows;
	int		pix;
	int		x;
	int		y;
	int		win;
	int		ct_col;
	int		allcol;
	int		x_exit;
	int		y_exit;
	int		move;	
	char	*str;
	char	**array;
	void	*mlx;
	void	*window;
	void	*space;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*exit_open;
	void	*perso;
	void	*perso_2;
	void	*left;
	void	*right;
}	t_game;

//---------------------- ARRAY ----------------------

void	ft_exit_coord(t_game *g, int i, int j);
int		collectible(t_game *g, int i, int j);
char	*one_str(char *argvone, t_game *g, int fd, int x);
char	**ft_array(char *str, t_game *g);

//------------------ ERRORS & MAP -------------------

void	display_error(t_game *g, int x);
int		check_map(char **array, char *argvone, int lines);
void	ft_errors(int x);

//--------------------- MOVES -----------------------

int		ft_moves(int key_code, t_game *g);

//--------------------- WINDOW ----------------------

void	window_display(t_game *game, int i, int j);
void	init_struct(t_game *game, char *argvone);
int		ft_close_win(t_game *g);
void	ft_clear_images(t_game *game);

//--------------------- PATH FINDING -----------------

int		col_count(char **array);
void	ft_col_coord(char **array, t_col *col);
void	init_struct_collec(t_game *g, t_col *col, char **array);
int		ft_check_col(char **array, t_col *col);
int		ft_pec(t_game *g, char **array);
int		path_finder_c(t_game *g, t_col *col, char **array);
int		path_manager_c(t_game *g);
int		path_finder_e(t_game *g, char **array, int i, int j);
int		path_manager_e(t_game *g);

//---------------------- UTILS ----------------------

int		char_is_ok(int c);
int		is_charset(int c);
void	ft_exit(t_game *g);
int		ft_strlen_sl(char *str);
int		ft_count_lines(char *argvone);
int		ft_count_rows(char *argvone, int lines, int fd, int i);
void	free_array(char **array);

#endif
