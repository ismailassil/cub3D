/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/07 15:07:29 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include "stdbool.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# define SUCCESS		0
# define FAIL			1
# define NO				1
# define SO				2
# define WE				3
# define EA				4
# define F				5
# define C				6
# define WHITESPACE		" \t\r\v\n\f"
# define PIXEL			32
# define WIDTH			1920
# define HEIGHT			1080
# define PLAYER_PX		10
# define PLAYER_MOVE	5
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define YELLOW			0xFFFF00
# define CYAN			0x00FFFF
# define MAGENTA		0xFF00FF

typedef struct s_directions
{
	char	*north;
	char	*west;
	char	*south;
	char	*east;
}			t_directions;

typedef struct s_colors
{
	char	*floor;
	char	*ceiling;
}			t_colors;

typedef struct s_data
{
	char			**data;
	char			**map;
	t_directions	*directions;
	t_colors		*colors;
	int				ylen;
}					t_data;

typedef struct s_tools
{
	int	i;
	int	j;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	floor;
	int	ceiling;
	int	which;
	int	error;
	int	flag;
	int	x;
	int	y;
	int	x_begin;
	int	y_max;
	int	x_max;
	int x_center;
	int y_center;
}		t_tools;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct s_point
{
	int	x;
	int	y;
	int	x_center;
	int	y_center;
	int	y_max;
	int	x_max;
	int	x_move;
	int	y_move;
}		t_point;

typedef struct s_cur_pos
{
	int	x_pixels;
	int	y_pixels;
	int	x_map;
	int	y_map;
}		t_cur_pos;

typedef struct s_pixel
{
	int	width;
	int	height;
}		t_pixel;

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t*	img;
	t_data			*info;
	t_point			position;
	t_cur_pos		cur_pos;
	t_pixel			pixel;
}					t_mlx;


/*	Check input		*/
bool	ft_check_input_file(int ac, char **av);
int		ft_open_file(char *file);

/*	Main functions	*/
void	ft_parse(int fd, t_data *data);
void	ft_raycasting(t_data *data);

/*	Raycasting functions	*/
void	ft_hook(mlx_key_data_t keydata, void *param);
void	ft_render(void *param);
void	ft_close(void *param);
void 	_mlx_error_(void);

/*	Raycasting utils functions	*/
void	ft_get_data(t_mlx *data);
void	ft_fill_square(t_mlx *data, int x, int y, int color);
void	ft_fill_pixel_player(t_mlx *data, int color);
void	ft_move_player(t_mlx *data, int key);

/*	Utils functions		*/
void	ft_get_position_of_player(char **map, t_point *p);
void	ft_exit(t_mlx *data);

/*	Check functions		*/
void	ft_check_unnessary_infos(t_data *parse);
void	ft_retrieve_and_check_directions(t_data *parse);
void	ft_retrieve_and_check_map(t_data *parse);
void	ft_check_if_surrounded_by_walls(t_data *parse);

/*	Check utils functions	*/
void	ft_check_directions(t_data *parse, t_tools *t);
void	ft_check_colors(t_data *parse, t_tools *t);
bool	ft_is_info(char *str, char *inf);
void	ft_add_information(t_data *parse, t_tools *t, int *dir, int which);

/*	Parsing utils functions	*/
bool	ft_isonly_whitespace(char *str);
void	ft_del_whitespace(char *str);
void	ft_remove_newline(char **line);

/*	t_utils functions	*/
int		ft_push_line(char *token, t_list **head);
int		ft_t_data_len(t_list *head);
t_list	*ft_last_node(t_list *top);
t_list	*ft_new_node(char *line);
void	ft_free_data(t_list **head);
void	ft_init_tools(t_tools *t);

/*	Utils functions	*/
void	p_error(char *str1, char *str2, int newline);
void	ft_check_allocation(void *ptr);
void	ft_free_all(t_data **parse);
void	ft_free_map(char ***map);
//////////////////////////////////////////////
void	ft_print_map(char **map);
//////////////////////////////////////////////
#endif