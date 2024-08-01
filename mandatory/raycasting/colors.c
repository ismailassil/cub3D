/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:56:10 by iassil            #+#    #+#             */
/*   Updated: 2024/05/26 16:38:56 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	rgba(int red, int green, int blue, int alpha)
{
	return ((uint32_t)red << 24 | (uint32_t)green << 16 \
		| (uint32_t)blue << 8 | (uint32_t)alpha);
}

int32_t	ft_reverse_color(int32_t colors)
{
	t_rgba	color;

	color.a = (colors >> 24) & 0xFF;
	color.r = (colors >> 16) & 0xFF;
	color.g = (colors >> 8) & 0xFF;
	color.b = colors & 0xFF;
	return (((uint32_t)color.b << 24) | ((uint32_t)color.g << 16) \
		| ((uint32_t)color.r << 8) | (uint32_t)color.a);
}
