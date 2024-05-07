/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:21:53 by iassil            #+#    #+#             */
/*   Updated: 2024/05/05 17:58:11 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

char	*ft_new(char **str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
		len++;
	ptr = _ft_calloc_((len + 1), sizeof(char));
	if (!ptr)
		return (free(*str), ptr = NULL, *str = NULL, NULL);
	while (i < len)
	{
		ptr[i] = (*str)[i];
		i++;
	}
	return (ptr);
}

char	*ft_newstr(char **str)
{
	char	*ptr;
	size_t	i;
	size_t	len;
	size_t	remainder;

	i = 0;
	len = _ft_strlen_(*str);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
		return (free(*str), *str = NULL, NULL);
	remainder = len - i;
	ptr = _ft_calloc_(remainder + 1, sizeof(char));
	if (!ptr)
		return (free(*str), *str = NULL, NULL);
	i++;
	len = 0;
	while (len < remainder)
		ptr[len++] = (*str)[i++];
	free(*str);
	*str = NULL;
	return (ptr);
}

void	*ft_allocate_read_check(ssize_t *nbyte, int *fd,
								char **buf, char **line)
{
	if (*fd < 0 || BUFFER_SIZE <= 0 || *fd > OPEN_MAX)
		return (NULL);
	(*buf) = _ft_calloc_((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!(*buf))
		return (free((*line)), (*line) = NULL, NULL);
	*nbyte = read(*fd, *buf, BUFFER_SIZE);
	if (*nbyte < 0)
		return (free(*buf), *buf = NULL, \
				free(*line), *line = NULL, NULL);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char		*line[OPEN_MAX];
	char			*temp;
	char			*buf;
	ssize_t			nbyte;

	if (!ft_allocate_read_check(&nbyte, &fd, &buf, &line[fd]))
		return (NULL);
	while (nbyte > 0)
	{
		buf[nbyte] = '\0';
		line[fd] = _ft_strjoin_(&line[fd], buf);
		if (!line[fd])
			return (free(buf), buf = NULL, NULL);
		if (_ft_strchr_(line[fd]) == 1)
			break ;
		nbyte = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (!line[fd] || line[fd][0] == '\0')
		return (free(line[fd]), line[fd] = NULL, NULL);
	temp = ft_new(&line[fd]);
	if (!temp)
		return (NULL);
	line[fd] = ft_newstr(&line[fd]);
	return (temp);
}
