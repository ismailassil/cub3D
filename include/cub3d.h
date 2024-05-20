/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/20 19:32:15 by iassil           ###   ########.fr       */
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
# include <float.h>
# include "/Users/iassil/.MLX42/include/MLX42/MLX42.h"
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
# define PLAYER_PX		6
# define PLAYER_SPEED	5
# define ROT_SPEED		5
# define LINE			80
# define NUM_RAYS		WIDTH
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

typedef struct s_line
{
	int	x_begin;
	int	y_begin;
	int	x_end;
	int	y_end;
}		t_line;

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
	int		i;
	int		j;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		floor;
	int		ceiling;
	int		which;
	int		error;
	int		flag;
	int		x;
	int		y;
	int		x_begin;
	int		y_max;
	int		x_max;
	int		x_center;
	int		y_center;
	int		nextpx_x;
	int		current_x;
	int		nextpx_y;
	int		current_y;
	int		move_step;
}			t_tools;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct s_point
{
	int	x;
	int	y;
	int	y_max;
	int	x_max;
}		t_point;

typedef struct s_player
{
	int		x;
	int		y;
	int		turn_direction;
	int		walk_direction;
	int		num_of_rays;
	int		wall_strip_width;
	double	rotation_speed;
	double	rotation_angle;
	double	fov_angle;
}			t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	bool	is_up;
	bool	is_down;
	bool	is_left;
	bool	is_right;
	bool	wall_hit_content;
	bool	was_hit_vert;
}			t_ray;

typedef struct s_size
{
	int	width;
	int	height;
	int	win_width;
	int	win_height;
}		t_size;

typedef struct s_cube
{
	t_data			*info;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	t_size			size;
	t_ray			*rays;
}					t_cube;

typedef struct s_info
{
	// Windows
	int			win_width;
	int			win_height;
	// Player Coordinates
	int			px;
	int			py;
	// Tile
	int			xtile;
	int			ytile;
	// The intersection
	double		x_intersection;
	double		y_intersection;
	// The steps deltaX and deltaY
	long long	xstep;
	long long	ystep;
	// Angle
	double		ray_angle;
	// Ray directions
	bool		is_right;
	bool		is_down;
	bool		is_up;
	bool		is_left;
	// The next Horizantal Touch with X and Y
	double		next_horz_x;
	double		next_horz_y;
	// To check if hit wall
	bool		found_horz_wall;
	double		horz_wall_x;
	double		horz_wall_y;
	// The next Vertical Touch with X and Y
	double		next_vert_x;
	double		next_vert_y;
	// To check if hit wall
	bool		found_vert_wall;
	double		vertwallx;
	double		vertwally;
	/// Calculate the Vert and Horz distances and get the smallest value
	double		horz_dist;
	double		vert_dist;
}				t_info;

/*	Check input		*/
bool	ft_check_input_file(int ac, char **av);
int		ft_open_file(char *file);

/*	Main functions	*/
void	ft_parse(int fd, t_data *cube);
void	ft_raycasting(t_data *cube);

/*	Raycasting functions	*/
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_loop_hook(void *param);
void	ft_close_hook(void *param);
void	ft_cube_error(void);

/*	Raycasting utils functions	*/
void	ft_get_window_data(t_cube *cube);
void	ft_move_player(t_cube *cube);
void	ft_fill_square(t_cube *cube, int x, int y, int color);
void	ft_fill_pixel_player(t_cube *cube, int color);
void	ft_draw_line_of_view(t_cube *cube, int color);
void	ft_draw_line(t_cube *cube, t_line line, int color);

/*	Color functions		*/
int		rgba(int red, int green, int blue, int alpha);

/*	Utils functions		*/
void	ft_init_data(t_cube *cube);
void	ft_get_position_of_player(char **map, t_point *p);
void	ft_exit(t_cube *cube);

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