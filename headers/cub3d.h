/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 18:11:07 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include "stdbool.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include "../lib/minilibX/mlx.h"
# define SUCCESS	0
# define FAIL		1
# define NO			1
# define SO			2
# define WE			3
# define EA			4
# define F			5
# define C			6
# define WHITESPACE	" \t\r\v\n\f"

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
}		t_tools;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

/*	Check input		*/
bool	ft_check_input_file(int ac, char **av);
int		ft_open_file(char *file);

/*	Parsing	functions	*/
void	ft_parse(int fd, t_data *data);
void	ft_raycasting(t_data *data);

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