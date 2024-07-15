/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:24 by iassil            #+#    #+#             */
/*   Updated: 2024/07/14 09:04:20 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_push_line(char *token, t_list **head)
{
	t_list	*newnode;
	t_list	*last;

	newnode = ft_new_node(token);
	if (!head || !(*head))
		*head = newnode;
	else
	{
		last = ft_last_node(*head);
		last->next = newnode;
	}
	return (1);
}

t_list	*ft_new_node(char *line)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	ft_check_allocation(new);
	new->line = ft_strdup(line);
	new->next = NULL;
	return (new);
}

t_list	*ft_last_node(t_list *top)
{
	while (top && top->next)
		top = top->next;
	return (top);
}

int	ft_t_data_len(t_list *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	ft_free_data(t_list **head)
{
	t_list	*current;

	current = NULL;
	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current->line);
		current->line = NULL;
		free(current);
		current = NULL;
	}
	// free(*head);
	*head = NULL;
}
