/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:37:35 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/17 11:36:32 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <complex.h>
#include <stdio.h>

int	ft_size_list(t_list	*lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
char	**ft_to_2d(t_list *list)
{
	t_list	*tmp;
	char	**p;
	int		i;

	tmp = list;
	p = malloc((ft_size_list(list) + 1) * sizeof(char *));
	i = 0;
	if (!p)
		return (NULL);
	while (tmp)
	{
		p[i++] = tmp->line;
		tmp = tmp->next;
	}
	p[i] = NULL;
	return (p);	
}

int	my_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str && str1 && str[i] && str1[i])
	{
		if (str[i] != str1[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] == ' ' || s1[j] == '\t')
		j++;
	if (s1[j] == '\n')
		j++;
	if (s1[j] == '\0')
		return (1);
	while (s1 && s2 && s1[j] && s2[i])
	{
		if (s1[j] != s2[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}
int	ft_check_path(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 2;
	while (str && (str[i] == ' '))
		i++;
	j = i;
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	else
	{
		if (str[i] == '.' || str[i] == '/')
		{
			i++;
			if (str[i] == '\n' || str[i] == '\0')
				return (0);
			i++;
			if (str[i] == '\n' || str[i] == '\0')
				return (0);
			if (str[i] == ' ' || str[i] == '\t')
			{
				while (str && (str[i] == ' '))
					i++;
				if (str[i] == '\n' || str[i] == '\0')
					return (0);
			}
		}	
	}
	if (my_strcmp(str, "NO "))
	{
		data->path->north = ft_strdup(&str[j]);
		if (!data->path->north)
			return (0);
	}
	else if (my_strcmp(str, "SO "))
	{
		data->path->south = ft_strdup(&str[j]);
		if (!data->path->south)
			return (0);
	}
	else if (my_strcmp(str, "WE "))
	{
		data->path->west = ft_strdup(&str[j]);
		if (!data->path->west)
			return (0);
	}
	else if (my_strcmp(str, "EA "))
	{
		data->path->east = ft_strdup(&str[j]);
		if (!data->path->east)
			return (0);
	}
	return (1);
}

int	ft_count_semi(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	ft_check_num(char *str)
{
	int i;

	i = 0;
	while (str && str[i + 1] && str[i + 1] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else
			return (0);
		i++; 
	}
	return (1);
}

int	ft_check_range(char *str, t_data *data, int flag)
{
	int		i;
	static	int	a;
	int		z;
	int		t;

	i = 0;
	z = 1;
	t = 0;
	// printf("str == %s\n", str);
	while (str && (str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (printf("got here\n"), 0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			z = -1;
		i++;
	}
	while (str && str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break ;
			else if (str[i] != '\0')
				return (0);
		}
		t = t * 10 + str[i] - 48;
		i++;
	}
	t = t * z;
	if (t < 0 || t > 255)
		return (0);
	if (flag == 0)
	{
		if (a == 0)
			data->ceiling.red = t;
		else if (a == 1)
			data->ceiling.green = t;
		else if (a == 2)
			data->ceiling.blue = t;
		a++;
	}
	if (flag == 1)
	{
		if (a == 0)
			data->floor.red = t;
		else if (a == 1)
			data->floor.green = t;
		else if (a == 2)
			data->floor.blue = t;
		a++;
	}
	if (a == 3)
		a = 0;
	return (1);
}

int	ft_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0); 
	while (str && str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (printf("from here\n"), 0);
		i++;
	}
	return (1);
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));	
}

void ft_free_array(char **ar)
{
	int i;

	i = 0;
	while (ar && ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

int	ft_is_num(char *str, t_data *data)
{
	int		i;
	char	**ar;
	char	**ar1;
	int		w;

	1 && (i = 1, w = 0);
	while (str && (str[i] == ' '))
		i++;
	ar = ft_split(&str[i], ',');
	if (!ar)
		return (0);
	while (w <= 2)
	{
		if (w == 2)
		{
			i = 0;
			while (ar[w][i])
				i++;
			if (i != 0 && ar[w][i - 1] == '\n')
				ar[w][i - 1] = '\0';
		}
		if (!ft_num(ar[w]))
			return (ft_free_array(ar),0);
		w++;
	}
	w = 0;
	while (w <= 2)
	{
		if (w == 2)
		{
			i = 0;
			while (ar[w][i])
				i++;
			if (i != 0 && ar[w][i - 1] == '\n')
				ar[w][i - 1] = '\0';
		}
		int k = 0;
		while (str && (str[k] == ' '))
			k++;
		if (str && str[k] == 'C')
			k = 0;
		else
		 	k = 1;
		if (!ft_check_range(ar[w], data, k))
			return (printf("got here"),ft_free_array(ar), 0);
		w++;
	}
	return (ft_free_array(ar),1);
}

int	ft_check_color(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (ft_count_semi(str) == 2 && ft_is_num(str, data))
		return (1);
	return (0);
}

int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_put_direction(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			return (str[i]);
		i++;
	}
	return (0);
}

int ft_get_last_line(t_data *data, int count)
{
	while (data->data && data->data[count + 1])
		count++;
	if (!ft_find_char(data->data[count], '1'))
		return (-1337);
	return (count);
}

int	ft_size(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return(i);
}

int	ft_check2(t_data *data, int count)
{
	int k;
	int i;

	k = 0;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] && (ft_strlen (data->data[count]) < ft_strlen(data->data[count + 1])))
	{
		k = ft_my_strl2(data->data[count + 1]);
		while (k > i)
		{
			if (data->data[count + 1][k] == '0')
				return (0);
			k--;
		}
	}
	return (1);
}

int	ft_check3(t_data *data, int count)
{
	int k;
	int i;

	k = 0;
	count--;
	i = ft_my_strl2(data->data[count]);
	if (data->data[count + 1] && (ft_strlen(data->data[count]) > ft_strlen(data->data[count + 1])))
	{
		k = ft_my_strl2(data->data[count + 1]);
		while (i > k)
		{
			if (data->data[count][i] == '0')
				return (0);
			i--;
		}
	}
	return (1);
}

int	ft_check_map_borders(t_data *data, int count)
{
	int	i;

	i = 0;
	int a = count;
	int	last_line = ft_get_last_line(data, count);
	if ((last_line == -1337 && last_line != 0 && last_line != 1) || data->data[last_line - 1][0] == '\n')
		return (0);
	i = ft_size(data->data[last_line]) - 1;
	while (data->data[last_line][i] == ' ')
		i--;
	if (data->data[last_line][i] == '\n')
		return (0);
	if (!ft_find_char(data->data[count], '1') && !ft_find_char(data->data[count], ' ')
		&& !ft_find_char(data->data[count], '\n'))
		return (0);

	i = 0;
	while (data->data && data->data[count + 1])
	{
		i = 0;
		while (data->data[count][i])
		{
			if (data->data[count][i] == ' ' && data->data[count + 1]
				&& i <= ft_my_strl2(data->data[count + 1]) && (data->data[count + 1][i] == ' '))
				{
					int k = i;
					int a = count;
					while (data->data[a + 1])
					{
						if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1]) && (data->data[a + 1][k] == '0'
							|| data->data[a + 1][k] == 'N' || data->data[a + 1][k] == 'S'
							|| data->data[a + 1][k] == 'E' || data->data[a + 1][k] == 'W'))
							return(0);
						else if (data->data[a + 1] && k <= ft_my_strlen(data->data[a + 1]) && data->data[a + 1][k] == '1')
							break;
						a++;
					}
				}
			else if (data->data[count][i] == ' ' && data->data[count + 1]
				&& i <= ft_my_strl2(data->data[count + 1]) && (data->data[count + 1][i] == '0'|| data->data[count + 1][i] == 'N' || data->data[count + 1][i] == 'S'
							|| data->data[count + 1][i] == 'E' || data->data[count + 1][i] == 'W'))
				return (0);
			i++;
		}
		count++;
	}
	if (!ft_check2(data, count))
		return (0);
	i = 0;
	while (data->data && data->data[last_line] && last_line > a)
	{
		i = 0;
		while (data->data[last_line][i])
		{
			if (data->data[last_line][i] == ' ' && data->data[last_line - 1]
				&& i <= ft_my_strl2(data->data[last_line - 1]) && (data->data[last_line - 1][i] == ' '))
			{
				int k = i;
				int a = last_line;
				while (a != 0 && data->data[a - 1])
				{
					if (data->data[a - 1] && k <= ft_my_strlen(data->data[a - 1]) && (data->data[a - 1][k] == '0'
					|| data->data[a - 1][k] == 'N' || data->data[a - 1][k] == 'S'
					|| data->data[a - 1][k] == 'E' || data->data[a - 1][k] == 'W'))
						return(0);
					else if (data->data[a - 1] && k <= ft_my_strlen(data->data[a + 1]) && data->data[a - 1][k] == '1')
						break;
					a--;
				}
			}
			if (i <= ft_my_strl2(data->data[last_line - 1]) && data->data[last_line][i] == ' ' && data->data[last_line - 1] && 
				 (data->data[last_line - 1][i] == '0'|| data->data[last_line - 1][i] == 'N' || data->data[last_line - 1][i] == 'S'
				|| data->data[last_line - 1][i] == 'E' || data->data[last_line - 1][i] == 'W'))
				return (printf("here2?%s\n", data->data[last_line]), 0);
			i++;
		}
		last_line--;
	}
	if (!ft_check3(data, last_line))
		return (0);
	return (1);
}

int	ft_borders_utils(t_data *data, int count)
{
	int	l;
	int a;
	int	i;

	i = 0, a = 0;

	int kk = ft_get_last_line(data, count);
	while (data->data[kk][a])
	{
		if (data->data[kk][a] != '1' && data->data[kk][a] != ' ' && data->data[kk][a] != '\n')
			return (0);
		a++;
	}
	
	while (data->data && data->data[count])
	{
		i = 0;
		while (data->data[count][i] == ' ')
			i++;
		if (data->data[count][i] == '1')
		{
			l = ft_strlen(data->data[count]) - 1;
			if (data->data[count][l] && data->data[count][l] == '\n')
				l--;
			while (data->data[count][l] && (data->data[count][l] == ' ') && l >= 0)
				l--;
			if (data->data[count][l] != '1')
				return (0);
		}
		else
			return (0);
		count++;
	}
	return (1);
}



int	ft_map_validity(t_data	*data, int count)
{
	int	prev_line;
	int	line, i = 0, j = 0, player = 0;

	line = count;
	while (data->data && data->data[count])
	{
		if (ft_find_char(data->data[count], 'N') || ft_find_char(data->data[count], 'S') 
			|| ft_find_char(data->data[count], 'E') || ft_find_char(data->data[count], 'W'))
		{
			player++;
			data->direction = ft_put_direction(data->data[count]);
		}
		if (!ft_find_char(data->data[count], 'N') && !ft_find_char(data->data[count], 'S') 
			&& !ft_find_char(data->data[count], 'E') && !ft_find_char(data->data[count], 'W')
			&& !ft_find_char(data->data[count], '1') && !ft_find_char(data->data[count], '0')
			&& !ft_find_char(data->data[count], ' ') && !ft_find_char(data->data[count], '\n'))
				return (printf("here\n"), 0);
		count++;
	}
	if (player == 1 && ft_check_map_borders(data, line)
		&& ft_borders_utils(data, line))
		return (1);
	else
	 	return (printf("test111\n"), 0);
}

int	ft_find_chr(char *str)
{
	int	i, flag, flag1;

	i = 0;
	while (str && str[i])
	{
		flag = 0;
		flag = 0;
		if (str[0] == '\n')
			return (1);
		if (str[i] == 'N' || str[i] == 'W' || str[i] == 'S' || str[i] == 'E')
			flag = 1;
		if ((str[i] == '0' || str[i] == '1'))
			flag1 = 1;
		if (str[i] != 'N' && str[i] != 'W' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != '\n')
				return (0);
		if (str[i])
			i++;
	}
	if (flag == 1 && flag1 == 1)
		return (1);
	else if (flag == 0 && flag1 == 1)
		return (1);
	else
		return (0);
}

int	is_there(char *str, char *str1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str && str1 && str[i] && str1[j])
	{
		if (str[i] != str1[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	ft_my_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	if (i > 0)
		i--;
	while ( i >= 0 && str[i] && (str[i] != '1' || str[i] != '0'))
		i--;
	return (i);
}

int	inside_map_validity(t_data *data, int line)
{
	int	k;
	int a;
	int	i;

	k = 0;
	i = 0;
	line++;
	a = 0;
	while (data->data[line])
	{
		if (line != 0 && ft_my_strl2(data->data[line]) > ft_my_strl2(data->data[line - 1]))
		{
			k = ft_my_strl2(data->data[line - 1]);
			i = ft_my_strl2(data->data[line]);
			a  = 0;
			int ss = i - k + 1;
			if (i == 0 && k == 0)
				return (printf("hhhh\n"), 0);
			while (k < i && a != ss)
			{
				if (data->data[line][i] == '0')//|| data->data[line][i] == 'N' || data->data[line][i] == 'S'|| data->data[line][i] == 'E' || data->data[line][i] == 'W'
					return (printf("hhhh1\n"), 0);
				i--;
				a++;
			}
			return (1);
		}
		if (line != 0 && ft_my_strl2(data->data[line]) < ft_my_strl2(data->data[line - 1]))
		{
			a = 0;
			k = ft_my_strl2(data->data[line - 1]);
			i = ft_my_strl2(data->data[line]);
			if (i == 0 && k == 0)
				return (printf("hhhh2\n"), 0);
			while (i < k && a != i)
			{
				if (data->data[line - 1][k] == '0')//|| data->data[line - 1][k] == 'N' || data->data[line - 1][k] == 'S' || data->data[line - 1][k] == 'E' || data->data[line - 1][k] == 'W'
					return (printf("hhhh3\n"), 0);
				k--;
				a++;
			}
		}
		line++;
	}
	return (1);
}

int ft_size_map(t_data *data, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->data[j])
	{
		if (ft_find_char(data->data[j], '0') || ft_find_char(data->data[j], '1'))
			count++;
		j++;
	}
	return (count);
}

int ft_my_strl(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '1' || str[i] == '0')
			break ;
		i++;
	}
	return (i);
}

int ft_my_strl2(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str && str[i])
		i++;
	if (i > 0)
		i--;
	while (str && str[i] && i > 0)
	{
		if (str[i] == '1' || str[i] == '0')
			break ;
		i--;
	}
	return (i);
}

int	ft_borders(t_data *data, int i)
{
	int	k;
	int j;
	int	l;
	int last;

	k = 0;
	j = 0;
	l = 0;
	last = ft_get_last_line(data, i);
	while (data->data[i][j])
	{
		if (data->data[i][j] == '0')
			return (printf("from here\n"), 0);
		j++;
	}
	j = 0;
	while (data->data[last][j])
	{
		if (data->data[last][j] == '0')
			return (printf("from here1\n"), 0);
		j++;
	}
	while (data->data[i])
	{
		k = ft_my_strl(data->data[i]);
		l = ft_my_strl2(data->data[i]);
		if (data->data[i][k] != '1' || data->data[i][l] != '1')
			return (printf("from here 2\n"), 0);
		i++;
	}
	return (1);
}

int ft_chr(char *str, char c)
{
	int i = 0;

	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

int	ft_is_surounded(t_data *data, int count)
{
	int	i;

	i = 0;
	while (data->data[count])
	{
		i = 0;
		while (data->data[count][i])
		{
			if (data->data[count][i] == ' ' && ((i > 0 && data->data[count][i - 1] == '0')
				|| (ft_strlen(data->data[count]) >= i && data->data[count][i + 1] == '0')))
				return (0);
			i++;
		}
		count++;
	}
	return (1);
}

int	ft_is_strange(t_data *data, int count)
{
	int i;
	int k;

	i = 0;
	k = count;
	while (data->data[count + 1])
	{
		i = ft_strlen(data->data[count + 1]) - 1;
		while (i >= 0 && data->data[count + 1][i])
		{
			if (data->data[count + 1][i] == '0' && i >= ft_strlen(data->data[count]) - 1)
				return (printf("data = %s\n", data->data[count]), 0);
			i--;
		}
		count++;
	}
	count = k;
	while (count > 0 && data->data[count])
	{
		i = ft_strlen(data->data[count - 1]) - 1;
		int kk = ft_strlen(data->data[count]) - 1;
		if (data->data[count][kk] != '\n')
			kk++;
		while (i >= 0 && data->data[count - 1][i])
		{
			if (data->data[count - 1][i] == '0' && i >= kk)
				return (printf("data 33 = %s\n", data->data[count - 1]), 0);
			i--;
		}
		count++;
	}
	return (1);
}

int	ft_check_parse(t_data *data)
{
	int	i;
	int flag;
	int	count;
	int	j;

	i = 0;
	count = 0;
	flag = 0;
	while (data && data->data[i] &&(ft_strcmp(data->data[i], "\n")
			|| ft_strcmp(data->data[i], " ")))
	{
		i++;
	}
	int k = i + 5;
	while (data->data[i])
	{
		flag = 0;
		if (my_strcmp(data->data[i], "NO ") || my_strcmp(data->data[i], "SO ")
			|| my_strcmp(data->data[i], "WE ") || my_strcmp(data->data[i], "EA "))
		{
			flag = 1;
			if (!ft_check_path(data->data[i], data))
			{
				printf("error in texture in map1\n");
				return (0);
			}
			k = i;
			count++;
		}
		if (count == 6)
			break ;
		else if (my_strcmp(data->data[i], "F ") || my_strcmp(data->data[i], "C "))
		{
			flag = 1;
			if (!ft_check_color(data->data[i], data))
			{
				printf("error color in map\n");
				return (0);
			}
			k = i;
			count++;
		}
		if (count == 6)
			break ;
		if (!ft_strcmp2(data->data[i], "NO ") && 
		!ft_strcmp2(data->data[i], "SO ") && !ft_strcmp2(data->data[i], "\n")
		&& !ft_strcmp2(data->data[i], "WE ") && !ft_strcmp2(data->data[i], "EA ") && 
		!ft_strcmp2(data->data[i], "F ") && !ft_strcmp2(data->data[i], "C ") 
		 && count < 6)
			break ;
		i++;
	}
	int a = 0, kk = 0;
	while (data->data[a])
	{
		if (is_there(data->data[a], "NO ") || is_there(data->data[a], "SO ")
		|| is_there(data->data[a], "WE ") || is_there(data->data[a], "EA ") 
		|| is_there(data->data[a], "F ") || is_there(data->data[a], "C "))
		{
			kk++;
		}
		a++;
	}
	if (count > 6 || kk != 6)
	{
		printf("error duplicate element in map2\n");
		return (0);
	}
	int ii = ++i;
	while (data->data[ii])
	{
		if (!ft_find_chr(data->data[ii]))
		{
			printf("error unknown element\n");
			return (0);
		}
		ii++;
	}
	i = 0;
	kk = 0;
	while (data->data[i])
	{
		if (is_there(data->data[i], "NO ") || is_there(data->data[i], "SO ")
		|| is_there(data->data[i], "WE ") || is_there(data->data[i], "EA ") 
		|| is_there(data->data[i], "F ") || is_there(data->data[i], "C "))
		{
			kk++;
		}
		if (kk == 6)
		{
			i++;
			break;
		}
		i++;
	}

	while (data->data[i] && !ft_find_char(data->data[i], '1') && !ft_find_char(data->data[i], '0'))
		i++;
	if (!ft_map_validity(data, i) || !ft_borders(data, i) || ft_size_map(data, i) < 2  
		|| !inside_map_validity(data, i) || !ft_is_surounded(data, i) || !ft_is_strange(data, i))
	{
		printf("invalid map\n");
		return (0);
	}
	return (1);
}
