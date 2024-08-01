/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:46 by iassil            #+#    #+#             */
/*   Updated: 2024/08/01 11:37:27 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <math.h>
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
# define PLAYER_PX		10
# define PLAYER_SPEED	10
# define ROT_SPEED		10
# define LINE			80
# define NUM_RAYS		WIDTH
# define TILE			64
# define RANGE			5
# define MINIMAP		0.2
# define MAPWIDTH		300
# define MAPHEIGHT		200
# define SPACE			15
# define BORDER			5
# define MC				255
# define SECND			36
# define BAR			218
# define HEART			41
# define TURN			1

typedef struct s_rgba
{
	int32_t	a;
	int32_t	r;
	int32_t	g;
	int32_t	b;	
}			t_rgba;

typedef struct s_utils
{
	int	prev_line;
	int	line;
	int	i;
	int	j;
	int	player;
}		t_utils;

typedef struct s_dup
{
	int	i;
	int	ea;
	int	f;
	int	c;
	int	no;
	int	so;
	int	we;
}		t_dup;

typedef struct s_nrm
{
	int	i;
	int	flag;
	int	flag1;
}		t_nrm;

typedef struct s_map_utils
{
	int	k;
	int	j;
	int	l;
	int	last;
}		t_map_utils;

typedef struct s_validity
{
	int	k;
	int	ss;
	int	a;
	int	i;
}		t_validity;

typedef struct s_prase
{
	int	flag;
	int	k;
}		t_parse;

typedef struct s_path
{
	char	*north;
	char	*west;
	char	*south;
	char	*east;
}			t_path;

typedef struct s_colorss
{
	int	blue;
	int	red;
	int	green;
}		t_colorss;

typedef struct s_colors
{
	int	blue;
	int	red;
	int	green;
}		t_colors;

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
	char			direction;
	t_path			*path;
	t_colors		ceiling;
	t_colors		floor;
	int				ylen;
	int				xlen;
}					t_data;

typedef struct s_tools
{
	int			i;
	int			j;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			floor;
	int			ceiling;
	int			which;
	int			error;
	int			flag;
	int			x;
	int			y;
	int			x_begin;
	int			y_max;
	int			x_max;
	int			x_center;
	int			y_center;
	int			nextpx_x;
	int			current_x;
	int			nextpx_y;
	int			current_y;
	int			move_step;
	uint32_t	color;
}				t_tools;

typedef struct s_grid
{
	int		center_x;
	int		center_y;
	int		diff_x;
	int		diff_y;
	int		map_x;
	int		map_y;
	int		tile_x;
	int		tile_y;
	int		x;
	int		y;
}			t_grid;

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

typedef struct s_draw_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
}		t_draw_line;

typedef struct s_3dprojection
{
	mlx_texture_t	*img;
	int32_t			*img_px;
	float			ply_to_proj_plane;
	float			strip_wall_height;
	float			corrected_angle;
	float			offset;
	float			xcord;
	float			ycord;
	int				wall_top;
	int				wall_bottom;
	int				strip_height;
}					t_3dprojection;

typedef struct s_player
{
	float	x;
	float	y;
	int		turn_direction;
	int		ud_direction;
	int		lr_direction;
	int		reload;
	float	rotation_speed;
	float	rot_angle;
	float	fov_angle;
	bool	is_vertical;
	int32_t	mouse_x;
	int32_t	mouse_y;
}			t_player;

typedef struct s_weapon
{
	mlx_texture_t	*img;
	int32_t			*img_px;
	float			xcord;
	float			ycord;
	int32_t			color;
	unsigned int	x;
	unsigned int	y;
	unsigned int	nx;
	unsigned int	ny;
}					t_weapon;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
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

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*weapon[42];
	mlx_texture_t	*bar[218];
}					t_textures;

typedef struct s_cube
{
	t_data			*info;
	t_list			*file_input;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	t_colors		colors;
	t_size			size;
	t_textures		textures;
}					t_cube;

typedef struct s_info
{
	int			win_width;
	int			win_height;
	float		px;
	float		py;
	int			xtile;
	int			ytile;
	float		x_intersection;
	float		y_intersection;
	float		xstep;
	float		ystep;
	float		ray_angle;
	bool		is_right;
	bool		is_down;
	bool		is_up;
	bool		is_left;
	float		next_horz_x;
	float		next_horz_y;
	bool		found_horz_wall;
	float		horzwallx;
	float		horzwally;
	float		next_vert_x;
	float		next_vert_y;
	bool		found_vert_wall;
	float		vertwallx;
	float		vertwally;
	float		horz_dist;
	float		vert_dist;
}				t_info;

/*	To be deleted	*/
void		ft_map(t_data *info);

/*	Check input		*/
bool		ft_check_input_file(int ac, char **av);
int			ft_open_file(char *file, t_data *cube);

/*	Main functions	*/
void		ft_parse(int fd, t_data *cube);
void		ft_execute(t_data *info, t_list **file_input);

/*	MLX functions	*/
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_loop_hook(void *param);
void		ft_close_hook(void *param);
void		ft_destroy_cube(t_cube *cube);
void		ft_mlx_error(void);

/*	Player Movements functions	*/
void		ft_move_player(t_cube *cube);
void		ft_press_and_release_key(mlx_key_data_t keycube, \
				int *cube, int value);

/*	Execution functions	*/
void		ft_init_mlx_window(t_cube *cube);
void		ft_get_window_data(t_cube *data);
void		ft_initialize_data(t_cube *cube);

/*	3d Projection functions	*/
t_ray		ft_get_distance(t_cube *cube, float ray_angle);
void		ft_3dprojection(t_cube *cube, t_ray ray, int strip_id);

/*	3d Projection utils functions	*/
void		ft_get_wall_measurement(t_3dprojection *p);
void		ft_get_texture(t_cube *cube, t_3dprojection	*p, t_ray ray);
float		get_xcord(t_ray ray, mlx_texture_t *img);

/*	Texture functions			*/
void		ft_load_wall_textures(t_cube *cube);
void		ft_load_weapon_textures(t_cube *cube);
void		ft_load_bar_textures(t_cube *cube);

/*	Animation functions			*/
void		ft_put_weapon(t_cube *cube, mlx_texture_t *img);
void		ft_render_weapon(t_cube *cube);
void		ft_put_bar(t_cube *cube, mlx_texture_t *img);
void		ft_render_stat_bar(t_cube *cube);

/*	Ray Computation functions	*/
void		ft_walls_projection(t_cube *cube);
void		ft_render_rays(t_cube *cube);
void		ft_cast_all_rays(t_cube *cube);
void		ft_cast_ray(t_cube *cube, int id, float rayangle);
void		ft_init_directions(t_cube *cube, t_info *f, float rayangle);
float		ft_get_horizontal_distance(t_cube *cube, t_info *f);
float		ft_get_vertical_distance(t_cube *cube, t_info *f);
t_ray		ft_fill_ray_data(t_info *f);
void		ft_check_horizontal_wall_collision(t_cube *cube, t_info *f);
void		ft_check_vertical_wall_collision(t_cube *cube, t_info *f);
bool		ft_is_a_wall(t_cube *cube, float x, float y);
float		ft_get_point_to_point_distance(float x1, float y1, \
				float x2, float y2);

/*	Raycasting utils functions	*/
void		ft_fill_square(t_cube *cube, int x, int y, int color);
void		ft_fill_pixel_player(t_cube *cube, int color);
void		ft_draw_line_of_view(t_cube *cube, int color);
void		ft_draw_line(t_cube *cube, t_line line, int color);
void		ft_draw_floor_and_ceiling(t_cube *cube);

/*	Color functions	*/
uint32_t	rgba(int red, int green, int blue, int alpha);
int32_t		ft_reverse_color(int32_t colors);

/*	Utils functions	*/
void		ft_initialize_data(t_cube *cube);
void		ft_get_position_of_player(char **map, t_point *p);
void		ft_exit(t_cube *cube);

/*	Check functions	*/
void		ft_check_unnessary_infos(t_data *parse);
void		ft_retrieve_and_check_directions(t_data *parse);
void		ft_retrieve_and_check_map(t_data *parse);
void		ft_check_if_surrounded_by_walls(t_data *parse);

/*	Check utils functions	*/
void		ft_check_directions(t_data *parse, t_tools *t);
void		ft_check_colors(t_data *parse, t_tools *t);
bool		ft_is_info(char *str, char *inf);
void		ft_add_information(t_data *parse, t_tools *t, \
				int *dir, int which);

/*	Parsing utils functions	*/
bool		ft_isonly_whitespace(char *str);
void		ft_del_whitespace(char *str);
void		ft_remove_newline(char **line);

/*	t_utils functions	*/
int			ft_push_line(char *token, t_list **head);
int			ft_t_data_len(t_list *head);
t_list		*ft_last_node(t_list *top);
t_list		*ft_new_node(char *line);
void		ft_free_data(t_list **head);
void		ft_init_tools(t_tools *t);

/*	Utils functions	*/
void		p_error(char *str1, char *str2, int newline);
void		ft_check_allocation(void *ptr);
void		ft_free_all(t_data **parse);
void		ft_free_map(char ***map);
//////////////////////////////////////////////
void		ft_print_map(char **map);
//////////////////////////////////////////////
/*	Parsing		*/
t_list		*ft_get_map(int fd);
char		**ft_to_2d(t_list *list);
int			ft_check_parse(t_data *data);
int			ft_my_strlen(char *str);
int			ft_my_strl2(char *str);
void		ft_free_data_utils(t_data *data);
void		ft_free_list(t_list *tmp);
int			ft_size_list(t_list	*lst);
char		**ft_to_2d(t_list *list);
int			my_strcmp(char *str, char *str1);
int			ft_strcmp(char *s1, char *s2);
int			ft_strcmp2(char *s1, char *s2);
int			ft_count_semi(char *str);
int			ft_check_num(char *str);
int			ft_num(char *str);
int			is_alpha(char c);
void		ft_free_array(char **ar);
int			ft_check_color(char *str, t_data *data);
int			ft_find(char *str, char c);
int			ft_put_direction(char *str);
int			ft_get_last_line(t_data *data, int count);
int			ft_size(char *str);
int			ft_is_num(char *str, t_data *data);
int			ft_find_chr(char *str);
int			ft_map_validity(t_data	*data, int count);
int			ft_borders_utils(t_data *data, int count);
int			ft_check3(t_data *data, int count);
int			ft_check2(t_data *data, int count);
int			ft_check_map_borders(t_data *data, int count);
int			ft_size_map(t_data *data);
int			ft_my_strl(char *str);
int			is_there(char *str, char *str1);
int			ft_my_strlen(char *str);
int			ft_my_strl2(char *str);
int			ft_chr(char *str);
int			ft_is_surounded(t_data *data, int count);
int			ft_borders(t_data *data, int i);
int			ft_put_path(t_data *data, char *str, int j);
int			ft_check_path_utils(t_data *data, char *str, int i);
int			ft_check_path(char *str, t_data *data);
int			ft_is_strange_utils(t_data *data, int count, int i);
int			ft_is_strange(t_data *data, int count);
int			inside_map_validity(t_data *data, int line);
int			ft_check_range(char *str, t_data *data, int flag);
int			ft_check_range(char *str, t_data *data, int flag);
int			ft_is_num(char *str, t_data *data);
int			inside_map_validity(t_data *data, int line);
int			ft_map_valid_urils(int line, t_data *data, int a);
int			ft_check_parse1(t_data **data, int i, int *count, t_parse t);
int			ft_check_parse_utils(t_data *data, int count, int i);
int			my_strcmp1(char *str, char *str1);
int			my_strc1(char *str, char *str1);
int			ft_strcmp3(char *str, char c);
int			ft_duplicate(t_data *data);
int			ft_find1(char *str);
int			ft_player(char *str);
int			ft_check_player(t_data *data, int i);
/* Free Functions	*/
void		ft_fr_all_text(t_cube *cube);
void		ft_fr_all(t_cube *cube);
void		ft_fr_wtxt(t_cube *cube, int i);
void		ft_free_parsing(t_data *data, t_list **file_input);

#endif
