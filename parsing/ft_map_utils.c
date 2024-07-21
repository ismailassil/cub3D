/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:21:25 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/21 17:43:45 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	if (!p)
		return (NULL);
	i = 0;
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
