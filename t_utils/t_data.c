/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:24 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 01:13:30 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_push_line(char *token, t_data **head)
{
	t_data	*newnode;
	t_data	*last;

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

t_data	*ft_new_node(char *line)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	ft_check_allocation(new);
	new->line = ft_strdup(line);
	new->next = NULL;
	return (new);
}

t_data	*ft_last_node(t_data *top)
{
	while (top && top->next)
		top = top->next;
	return (top);
}

int	ft_t_data_len(t_data *head)
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

void	ft_free_data(t_data **head)
{
	t_data	*current;

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
	free(*head);
	*head = NULL;
}
