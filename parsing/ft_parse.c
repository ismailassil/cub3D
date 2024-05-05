/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:48:38 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 01:49:14 by iassil           ###   ########.fr       */
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
	t->error = 0;
}

void	ft_add_direction(t_data *parse, t_tools *t, int *dir, int which)
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
		ft_free_all(&parse);
	}
	parse->directions[t->j++] = parse->data[t->i];
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

void	ft_retrieve_directions(t_data *parse)
{
	t_tools	t;

	ft_init_tools(&t);
	parse->directions = malloc(sizeof(char *) * 5);
	ft_check_allocation(parse->directions);
	while (parse->data && parse->data[t.i])
	{
		if (ft_strncmp(parse->data[t.i], "NO", 3))
			ft_add_direction(parse, &t, &t.no, NO);
		else if (ft_strncmp(parse->data[t.i], "SO", 3))
			ft_add_direction(parse, &t, &t.so, SO);
		else if (ft_strncmp(parse->data[t.i], "WE", 3))
			ft_add_direction(parse, &t, &t.we, WE);
		else if (ft_strncmp(parse->data[t.i], "EA", 3))
			ft_add_direction(parse, &t, &t.ea, EA);
		t.i++;
	}
	parse->directions[t.j] = 0;
	ft_check_directions(parse, &t);
}

void	ft_retrieve_map(t_data *parse)
{
	(void)parse;
}

void	ft_check_validity(t_data *parse)
{
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
