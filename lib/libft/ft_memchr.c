/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:47:44 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 00:17:05 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	unsigned const char	*ptr;

	i = 0;
	ptr = (unsigned const char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
