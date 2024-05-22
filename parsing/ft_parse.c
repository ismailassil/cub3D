/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:48:38 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:04:28 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*	function prototype	*/
void	ft_retrieve_data_from_fd(int fd, t_list **map);
char	**ft_data_to_2d_map(t_list *map);
void	ft_check_validity(t_data *parse);
////////////////////////////////////////////////////////////////

void	ft_parse(int fd, t_data *parse)
{
	t_list	*_map_;

	_map_ = NULL;
	ft_retrieve_data_from_fd(fd, &_map_);
	parse = malloc(sizeof(t_data));
	ft_check_allocation(parse);
	parse->map = NULL;
	parse->data = ft_data_to_2d_map(_map_);
	ft_check_validity(parse);
	ft_print_map(parse->map);
	ft_free_map(&parse->map);
}

char	**ft_data_to_2d_map(t_list *map)
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
			break ;
		ft_remove_newline(&line);
		ft_push_line(line, map);
		free(line);
	}
	close(fd);
}

void	ft_check_validity(t_data *parse)
{
	ft_check_unnessary_infos(parse);
	ft_retrieve_and_check_directions(parse);
	ft_retrieve_and_check_map(parse);
	ft_check_if_surrounded_by_walls(parse);
}
