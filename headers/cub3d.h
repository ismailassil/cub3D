/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:30:46 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 01:40:09 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include "stdbool.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include </usr/local/include/mlx.h>
# define SUCCESS	0
# define FAIL		1
# define NO			1
# define SO			2
# define WE			3
# define EA			4

typedef struct s_map
{
	char	**data;
	char	**directions;
	char	**map;
}			t_map;

typedef struct s_tools
{
	int	i;
	int	j;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	which;
	int	error;
}		t_tools;

typedef struct s_data
{
	char			*line;
	struct s_data	*next;
}					t_data;

/*	Check input		*/
bool	ft_check_input_file(int ac, char **av);
int		ft_open_file(char *file);

/*	Parsing	functions	*/
void	ft_parse(int fd, t_data *data);

/*	t_utils functions	*/
int		ft_push_line(char *token, t_data **head);
int		ft_t_data_len(t_data *head);
t_data	*ft_last_node(t_data *top);
t_data	*ft_new_node(char *line);
void	ft_free_data(t_data **head);

/*	Utils functions	*/
void	p_error(char *str1, char *str2, int newline);
void	ft_check_allocation(void *ptr);
void	ft_free_map(char ***map);
//////////////////////////////////////////////
void	ft_print_map(char **map);
//////////////////////////////////////////////
#endif