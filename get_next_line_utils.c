/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirje <mmirje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:28:00 by mmirje            #+#    #+#             */
/*   Updated: 2024/11/11 11:31:23 by mmirje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ('\0' == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	void			*str;
	size_t			i;

	i = 0;
	if (count && size && (count > (UINT_MAX / size)))
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ptr = (unsigned char *)str;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (str);
}

size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	*ft_memcpy(void dst, const void *src, size_t n)
{
	unsigned char	*dstptr;

	dstptr = (unsigned char *)dst;
	if (!dstptr && !src)
		return (NULL);
	while (n > 0)
	{
		*dstptr++ = *(char *)src++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_len(s1);
	s2_len = ft_len(s2);
	str = (char *)malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (!str)
		return (NULL);
	ft_memcpy = (str, s1, s1_len);
	ft_memcpy = (str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
