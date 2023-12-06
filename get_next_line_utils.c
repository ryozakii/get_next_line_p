/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:15 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/21 13:05:30 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == (char) c)
		return ((char *)s + i);
	return (0);
}

void	*ft_memmove(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return ((char *)dst);
	if (!src && !dst)
		return ((char *)dst);
	while (i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	ft_bzero(void *s, size_t n)
{
	if (n >= 0)
	{
		while (n)
		{
			*(char *)s = '\0';
			n--;
			s++;
		}
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*t;
	size_t	s1l;
	size_t	s2l;
	size_t	i;

	i = -1;
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	t = malloc(s1l + s2l + 1);
	if (!t)
		return (0);
	while (++i < s1l)
		t[i] = s1[i];
	i = -1;
	while (++i < s2l)
		t[s1l + i] = s2[i];
	t[s1l + i] = 0;
	free(s1);
	free(s2);
	return (t);
}
