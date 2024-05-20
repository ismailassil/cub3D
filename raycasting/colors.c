/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:56:10 by iassil            #+#    #+#             */
/*   Updated: 2024/05/19 17:25:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int rgba(int red, int green, int blue, int alpha)
{
	return ((unsigned int)red << 24 | (unsigned int)green << 16 \
		| (unsigned int)blue << 8 | (unsigned int)alpha);
}
