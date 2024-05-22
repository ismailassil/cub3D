/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:46:12 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:04:58 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_check_rest(t_data *parse, char *str, int *flag)
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
	else if (!ft_is_info(str, "NO") && !ft_is_info(str, "SO")
		&& !ft_is_info(str, "WE") && !ft_is_info(str, "EA")
		&& !ft_is_info(str, "F") && !ft_is_info(str, "C")
		&& !ft_is_info(str, "1") && !ft_is_info(str, "0")
		&& !ft_is_info(str, "N") && !ft_is_info(str, "S")
		&& !ft_is_info(str, "E") && !ft_is_info(str, "W"))
	{
		p_error("unnecessary information has been found", NULL, 1);
		ft_free_map(&parse->data);
		free(parse);
		exit(FAIL);
	}
}

void	ft_check_unnessary_infos(t_data *parse)
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
			ft_check_rest(parse, parse->data[t.i], &t.flag);
		t.i++;
	}
}

void	ft_retrieve_and_check_directions(t_data *parse)
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

void	ft_retrieve_and_check_map(t_data *parse)
{
	(void)parse;
}

void	ft_check_if_surrounded_by_walls(t_data *parse)
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
