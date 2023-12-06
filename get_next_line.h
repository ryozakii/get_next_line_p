/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:15:04 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/21 13:06:25 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup2(char *src, char *remain, int *n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(char *dst, char *src, size_t len);
#endif