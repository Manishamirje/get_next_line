/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirje <mmirje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:27:57 by mmirje            #+#    #+#             */
/*   Updated: 2024/11/05 12:27:58 by mmirje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *r_buffer)
{
	ssize_t	r_len;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(r_buffer, '\n'))
	{
		r_len = read(fd, buffer, BUFFER_SIZE);
		if (r_len == -1)
		{
			free(buffer);
			free(r_buffer);
			return (NULL);
		}
		buffer[r_len] = '\0';
		r_buffer = ft_strjoin(r_buffer, buffer);
		free(buffer);
		return (r_buffer);
	}
}

char	*get_next_line(int fd)
{
	static char *right_buffer;
	char		*left_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	right_buffer = ft_read(fd, right_buffer);
	if (!right_buffer)
		return (NULL);
}
