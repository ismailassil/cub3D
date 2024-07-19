/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:45:29 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/17 09:33:14 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_list(t_list *lst)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->line);
		free(prev);
	}
}

t_list *ft_new_nod(char *str)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = ft_strdup(str);
	if (new->line == NULL)
		return (free(new), NULL);
	new->next = NULL;
	return (new);
}

t_list	*ft_add_list(t_list *lst, char *str)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		lst = ft_new_nod(str);
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_node(str);
		if (tmp->next == NULL)
		{
			ft_free_list(tmp);
			return (NULL);
		}
	}
	return (lst);
}

t_list	*ft_get_map(int fd)
{
	t_list	*lst;
	char	*str;

	lst = NULL;
	str = get_next_line(fd);
	if (!str)
		return (perror("empty file"), NULL);
	lst = ft_add_list(lst, str);
	if (!lst)
		return (free(str), NULL);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
		{
			break ;
		}
	 	lst = ft_add_list(lst, str);
 		free(str);
	}
	return (lst);
}
