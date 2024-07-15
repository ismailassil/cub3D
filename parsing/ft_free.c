/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:32:43 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/14 09:37:16 by ybellakr         ###   ########.fr       */
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
	free(data->path->east);
	free(data->path->north);
	free(data->path->south);
	free(data->path->west);
	free(data->path);
}
