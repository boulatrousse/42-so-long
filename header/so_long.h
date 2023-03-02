/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:16:45 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/02 10:07:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/include/libft.h"
# include "../minilibx_linux/mlx.h"
# define KEY_ESC 	65307
# define KEY_UP 	119
# define KEY_DOWN	115
# define KEY_LEFT	97
# define KEY_RIGHT	100 

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
	char	*tmp_str;
	char	**array;
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

void	free_array(char **array);
char	*one_str(char *argvone, t_game *g, int fd, int x);
char	**ft_array(char *str);

//------------------ ERRORS & MAP -------------------

int		check_map(char **array, char *argvone, int lines, char *str);
void	display_error(char *str);
void	free_strings(t_game *game);
void	free_mlx(t_game *game);
void	free_window(t_game *game);
void	map_format_error(char *str, char **array);
void	close_fd(void);

//--------------------- COORD -----------------------

void	ft_exit_coord(t_game *g, int i, int j);
void	ft_coord_perso(t_game *g);
void	ft_col_coord(char **array, t_col *col);

//--------------------- MOVES -----------------------

int		ft_moves(int key_code, t_game *g);

//--------------------- INIT ----------------------

void	init_struct(t_game *game, char *argvone);
void	init_images(t_game *game);
void	init_struct_collec(t_game *g, t_col *col);

//--------------------- IMAGES ---------------------

void	check_images(t_game *game);
void	ft_clear_images_character(t_game *game);
void	window_display(t_game *game, int i, int j);

//--------------------- PATH FINDING -----------------

int		ft_check_col(char **array, t_col *col);
int		check_trap(t_game *g, char **array);
int		path_finder_c(t_game *g, t_col *col, char **array);
int		path_manager_c(t_game *g);
int		path_finder_e(t_game *g, char **array, int i, int j);
int		path_manager_e(t_game *g);
void	free_pathfinding_c(char *str, char **array);

//---------------------- UTILS ----------------------

int		char_is_ok(int c);
int		is_charset(int c);
int		is_charset_col(int c, t_col *col);
int		ft_strlen_sl(char *str);
int		ft_count_lines(char *argvone);
int		ft_count_rows(char *argvone, int lines, int fd, int i);
int		count_collectible(t_game *g);
void	ft_exit(t_game *g);
int		ft_close_win(t_game *g);

#endif
