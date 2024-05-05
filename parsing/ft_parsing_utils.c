/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:39:20 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 17:59:05 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	ft_isonly_whitespace(char *str)
{
	int	i;

	i = 0;
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

void	ft_remove_newline(char **line)
{
	if (line && *line && (*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
}
