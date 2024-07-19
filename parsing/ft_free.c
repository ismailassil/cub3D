/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:32:43 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/16 09:27:48 by ybellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_data_utils(t_data *data)
{
	int i;

	i = 0;
	// while (data && data->data && data->data[i])
	// {
	// 	free(data->data[i]);
	// 	i++;		
	// }
	i = 0;
	// while (data && data->data && data->map[i])
	// {
	// 	free(data->map[i]);
	// 	i++;		
	// }
	if (data->path->east)
		free(data->path->east);
	if (data->path->north)
		free(data->path->north);
	if (data->path->south)
		free(data->path->south);
	if (data->path->west)
		free(data->path->west);
	if (data->path)
		free(data->path);
}
