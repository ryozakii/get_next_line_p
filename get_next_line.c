/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:49:33 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/21 13:02:00 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	remain[BUFFER_SIZE + 1];
	char		*line;
	int			n;
	int			r;

	line = NULL;
	n = 0;
	if (read(fd, line, 0) != -1 && BUFFER_SIZE > 0)
	{
		while (ft_bzero(buf, BUFFER_SIZE) && !n)
		{
			if (*remain)
				line = ft_strdup2(remain, remain, &n);
			if (!n)
				r = read(fd, buf, BUFFER_SIZE);
			if (n || r <= 0)
				break ;
			buf[r] = 0;
			line = ft_strjoin(line, ft_strdup2(buf, remain, &n));
		}
	}
	else
		ft_bzero(remain, BUFFER_SIZE + 1);
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
//  int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("read_error.txt", O_CREAT | O_RDWR, 00777);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
	// close(fd);
	// line = get_next_line(fd);
	// printf("%s", line);
	// fd = open("read_error.txt", O_CREAT | O_RDWR, 00777);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
//}
