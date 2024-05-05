/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:48:38 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 16:43:29 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_free_all(t_data **parse)
{
	ft_free_map(&(*parse)->data);
	free((*parse)->directions);
	free(*parse);
	exit(FAIL);
}

char	**ft_data_to_map(t_list *map)
{
	char	**ptr;
	t_list	*head;
	int		i;

	i = 0;
	ptr = malloc((ft_t_data_len(map) + 1) * sizeof(char *));
	ft_check_allocation(ptr);
	head = map;
	while (head)
	{
		ptr[i++] = ft_strdup(head->line);
		head = head->next;
	}
	ptr[i] = 0;
	ft_free_data(&map);
	return (ptr);
}

void	ft_if_surrounded_by_walls(t_data *parse)
{
	int	i;

	i = 0;
	while (parse->map && parse->map[i])
	{
		if (parse->map[i][0] != '1'
			|| parse->map[i][ft_strlen(parse->map[i]) - 1] != '1')
		{
			p_error("map is not surrounded by walls", NULL, 1);
			ft_free_all(&parse);
		}
		i++;
	}
}

void	ft_init_tools(t_tools *t)
{
	t->i = 0;
	t->j = 0;
	t->ea = 0;
	t->no = 0;
	t->so = 0;
	t->ea = 0;
	t->we = 0;
	t->floor = 0;
	t->ceiling = 0;
	t->error = 0;
	t->flag = 0;
}

void	ft_add_data(t_data *parse, t_tools *t, int which)
{
	if (which == NO)
		parse->directions->north = parse->data[t->i];
	else if (which == SO)
		parse->directions->south = parse->data[t->i];
	else if (which == EA)
		parse->directions->east = parse->data[t->i];
	else if (which == WE)
		parse->directions->west = parse->data[t->i];
	else if (which == F)
		parse->colors->floor = parse->data[t->i];
	else if (which == C)
		parse->colors->ceiling = parse->data[t->i];	
}

void	ft_add_information(t_data *parse, t_tools *t, int *dir, int which)
{
	(*dir)++;
	if ((*dir) >= 2)
	{
		if (which == NO)
			p_error("found an extra `NO` (North texture).", NULL, 1);
		else if (which == SO)
			p_error("found an extra `SO` (South texture).", NULL, 1);
		else if (which == EA)
			p_error("found an extra `EA` (East texture).", NULL, 1);
		else if (which == WE)
			p_error("found an extra `WE` (West texture).", NULL, 1);
		else if (which == F)
			p_error("found an extra `F` (Floor color).", NULL, 1);
		else if (which == C)
			p_error("found an extra `C` (Ceiling color).", NULL, 1);
		ft_free_all(&parse);
	}
	ft_add_data(parse, t, which);
}

void	ft_check_directions(t_data *parse, t_tools *t)
{
	if (t->no == 0)
	{
		p_error("`NO` (North texture) has not been found.", NULL, 1);
		t->error = 1;
	}
	else if (t->so == 0)
	{
		p_error("`SO` (South texture) has not been found.", NULL, 1);
		t->error = 1;
	}
	else if (t->we == 0)
	{
		p_error("`WE` (West texture) has not been found.", NULL, 1);
		t->error = 1;
	}
	else if (t->ea == 0)
	{
		p_error("`EA` (East texture) has not been found.", NULL, 1);
		t->error = 1;
	}
	else if (t->error)
		ft_free_all(&parse);
}

void	ft_check_colors(t_data *parse, t_tools *t)
{
	t->error = 0;
	if (t->floor == 0)
	{
		p_error("`F` (Floor color) has not been found.", NULL, 1);
		t->error = 1;
	}
	if (t->ceiling == 0)
	{
		p_error("`C` (Ceiling color) has not been found.", NULL, 1);
		t->error = 1;
	}
	else if (t->error)
		ft_free_all(&parse);
}

bool	ft_is_info(char *str, char *inf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		while (ft_strchr(WHITESPACE, str[i]))
			i++;
		if (!str[i])
			return (false);
		while (str[i] && inf[j] && str[i] == inf[j])
			(1) && (i++, j++);
		if (!inf[j])
			break ;
		else
			return (false);
	}
	return (true);
}

void	ft_retrieve_directions(t_data *parse)
{
	t_tools	t;

	ft_init_tools(&t);
	parse->directions = malloc(sizeof(t_directions));
	ft_check_allocation(parse->directions);
	parse->colors = malloc(sizeof(t_colors));
	ft_check_allocation(parse->colors);
	while (parse->data && parse->data[t.i])
	{
		if (ft_is_info(parse->data[t.i], "NO"))
			ft_add_information(parse, &t, &t.no, NO);
		else if (ft_is_info(parse->data[t.i], "SO"))
			ft_add_information(parse, &t, &t.so, SO);
		else if (ft_is_info(parse->data[t.i], "WE"))
			ft_add_information(parse, &t, &t.we, WE);
		else if (ft_is_info(parse->data[t.i], "EA"))
			ft_add_information(parse, &t, &t.ea, EA);
		else if (ft_is_info(parse->data[t.i], "F"))
			ft_add_information(parse, &t, &t.ea, F);
		else if (ft_is_info(parse->data[t.i], "C"))
			ft_add_information(parse, &t, &t.ea, C);
		t.i++;
	}
	ft_check_directions(parse, &t);
	ft_check_colors(parse, &t);
}

void	ft_retrieve_map(t_data *parse)
{
	(void)parse;
}

bool	ft_isonly_whitespace(char *str)
{
	int	i;

	while (str && str[i])
	{
		if (ft_strchr(WHITESPACE, str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

void	ft_del_whitespace(char *str)
{
	if (str && ft_isonly_whitespace(str))
		str[0] = '\0';
}

void	ft_check_rest(t_data *parse, char *str, int *flag)
{
	if (ft_is_info(str, "1") || ft_is_info(str, "0") || ft_is_info(str, "P"))
	{
		(*flag)++;
		if (*flag != 7)
		{
			p_error("the map should be at the bottom of the file", NULL, 1);
			ft_free_map(&parse->data);
			free(parse);
			exit(FAIL);
		}
	}
	else if (!ft_is_info(str, "NO") && !ft_is_info(str, "SO") && !ft_is_info(str, "WE")
				&& !ft_is_info(str, "EA") && !ft_is_info(str, "F") && !ft_is_info(str, "C")
				&& !ft_is_info(str, "1") && !ft_is_info(str, "0") && !ft_is_info(str, "N")
				&& !ft_is_info(str, "S") && !ft_is_info(str, "E") && !ft_is_info(str, "W"))
	{
		p_error("unnecessary information has been found", NULL, 1);
		ft_free_map(&parse->data);
		free(parse);
		exit(FAIL);
	}
}

void	ft_check_unnessary_info(t_data *parse)
{
	t_tools	t;

	ft_init_tools(&t);
	while (parse->data && parse->data[t.i])
	{
		ft_del_whitespace(parse->data[t.i]);
		if (!parse->data[t.i])
			;
		else if (ft_is_info(parse->data[t.i], "NO"))
			t.flag++;
		else if (ft_is_info(parse->data[t.i], "SO"))
			t.flag++;
		else if (ft_is_info(parse->data[t.i], "WE"))
			t.flag++;
		else if (ft_is_info(parse->data[t.i], "EA"))
			t.flag++;
		else if (ft_is_info(parse->data[t.i], "F"))
			t.flag++;
		else if (ft_is_info(parse->data[t.i], "C"))
			t.flag++;
		else
			ft_check_rest();
		t.i++;
	}
}

void	ft_check_validity(t_data *parse)
{
	ft_check_unnessary_info(parse);
	ft_retrieve_directions(parse);
	ft_retrieve_map(parse);
	ft_if_surrounded_by_walls(parse);
}

void	ft_remove_newline(char **line)
{
	if (line && *line && (*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
}

void	ft_retrieve_data_from_fd(int fd, t_list **map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		p_error("file is empty", NULL, 1);
		(close(fd), free(*map), exit(FAIL));
	}
	ft_remove_newline(&line);
	ft_push_line(line, map);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		ft_remove_newline(&line);
		ft_push_line(line, map);
		free(line);
	}
	close(fd);
}

void	ft_parse(int fd, t_list *_map_)
{
	t_data	*parse;

	ft_retrieve_data_from_fd(fd, &_map_);
	parse = malloc(sizeof(t_data));
	ft_check_allocation(parse);
	parse->map = NULL;
	parse->data = ft_data_to_map(_map_);
	ft_check_validity(parse);
	ft_print_map(parse->map);
	ft_free_map(&parse->map);
}
