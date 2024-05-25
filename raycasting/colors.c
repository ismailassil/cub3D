/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:56:10 by iassil            #+#    #+#             */
/*   Updated: 2024/05/25 18:38:09 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	rgba(int red, int green, int blue, int alpha)
{
	return ((uint32_t)red << 24 | (uint32_t)green << 16 \
		| (uint32_t)blue << 8 | (uint32_t)alpha);
}
