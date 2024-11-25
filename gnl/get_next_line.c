/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirje <mmirje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:03 by mmirje            #+#    #+#             */
/*   Updated: 2024/05/28 11:27:35 by mmirje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_right_buffer(char *r_buffer)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!r_buffer)
		return (free (r_buffer), NULL);
	while (r_buffer[i] && r_buffer[i] != '\n')
		i++;
	if (!r_buffer[i])
	{
		free(r_buffer);
		return (NULL);
	}
	buffer = (char *)ft_calloc((ft_len(r_buffer) - i) + 1, sizeof(char));
	if (!buffer)
		return (free(r_buffer), NULL);
	while (r_buffer[i])
		buffer[j++] = r_buffer[++i];
	buffer[j] = '\0';
	if (!*buffer)
		return (free (buffer), free (r_buffer), NULL);
	free(r_buffer);
	return (buffer);
}

static char	*ft_left_buffer(char *r_buffer)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (!r_buffer[i])
		return (NULL);
	while (r_buffer[i] && r_buffer[i] != '\n')
		i++;
	buff = (char *)ft_calloc(i + 2, sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (r_buffer[i] && r_buffer[i] != '\n')
	{
		buff[i] = r_buffer[i];
		i++;
	}
	if (r_buffer[i] == '\n')
	{
		buff[i] = r_buffer[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

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
		if (0 == r_len)
			break ;
	}
	free (buffer);
	return (r_buffer);
}

char	*get_next_line(int fd)
{
	static char	*right_buffer;
	char		*left_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	right_buffer = ft_read(fd, right_buffer);
	if (!right_buffer)
		return (NULL);
	left_buffer = ft_left_buffer(right_buffer);
	right_buffer = ft_right_buffer(right_buffer);
	return (left_buffer);
}

/*int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (count < 20)
	{
		next_line = get_next_line(fd);
		printf("next_line:%s", next_line);
		free(next_line);
		count++;
	}
	close(fd);
	return (0);
}*/
