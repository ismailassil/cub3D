/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:46:14 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 21:31:35 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_mlx
{
	t_data			*info;
	mlx_t			*mlx;
	mlx_image_t*	img;
	int				width;
	int				height;
}					t_mlx;
