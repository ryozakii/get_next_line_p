/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:49:33 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/15 13:23:37 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	remain[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			n;
	int			r;

	line = NULL;
	n = 0;
	if (read(fd, line, 0) != -1 && BUFFER_SIZE > 0)
	{
		while (ft_bzero(buf, BUFFER_SIZE) && !n)
		{
			if (*remain[fd])
				line = ft_strdup2(remain[fd], remain[fd], &n);
			if (!n)
				r = read(fd, buf, BUFFER_SIZE);
			if (n || r <= 0)
				break ;
			buf[r] = 0;
			line = ft_strjoin(line, ft_strdup2(buf, remain[fd], &n));
		}
	}	
	else if (fd >= 0)
		ft_bzero(remain[fd], BUFFER_SIZE + 1);
	return (line);
}

char	*ft_strdup2(char *src, char *remain, int *n)
{
	char			*l1;
	size_t			l;
	char			*t;
	char			*tm;

	l1 = ft_strchr(src, '\n');
	if (l1)
	{
		l = l1 - src + 1;
		*n = 1;
	}
	else
		l = ft_strlen(src);
	t = malloc(l + 1);
	if (!t)
		return (0);
	tm = t;
	while (l--)
		*t++ = *src++;
	*t = '\0';
	*remain = '\0';
	if (*src)
		ft_memmove(remain, src, ft_strlen(src));
	return (tm);
}
