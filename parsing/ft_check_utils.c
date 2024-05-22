/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:41:04 by iassil            #+#    #+#             */
/*   Updated: 2024/05/23 00:04:46 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

static void	ft_add_data(t_data *parse, t_tools *t, int which)
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
