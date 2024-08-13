/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:38:49 by ybellakr          #+#    #+#             */
/*   Updated: 2024/08/13 22:48:07 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	skipspace_strcmp(char *str, char *str1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] == str1[j])
	{
		j++;
		i++;
	}
	if (str1[j] == '\0')
		return (1);
	return (0);
}
