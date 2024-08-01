/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:32:43 by ybellakr          #+#    #+#             */
/*   Updated: 2024/07/23 10:29:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_free_data_utils(t_data *data)
{
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
