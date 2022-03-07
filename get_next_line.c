/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:32:21 by deleusis          #+#    #+#             */
/*   Updated: 2021/11/27 19:44:08 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_buf(int fd, char *b, int *i)
{
	char	*line;
	int		j;
	int		count;

	if (b[*i] == '\n')
		(*i)++;
	if (b[*i] == '\0')
	{
		count = read(fd, b, BUFFER_SIZE);
		if (count <= 0)
			return (NULL);
		b[count] = '\0';
		*i = 0;
	}
	j = 0;
	while (b[*i + j] && b[*i + j] != '\n')
		j++;
	line = ((char *)malloc(sizeof (char) * (j + 1 + (b[*i + j] == '\n'))));
	return (line);
}

int	ft_strcpy(char *b, char *line, int *i)
{
	int	j;

	j = 0;
	while (b[*i] && b[*i] != '\n')
		line[j++] = b[(*i)++];
	if (b[*i] == '\n')
		line [j++] = '\n';
	line[j] = '\0';
	return (j);
}

char	*get_line(char *b, int *i, int *j, char *line)
{
	char		*line2;

	line2 = malloc (*j + 1 + (b[(*i) + (*j)] == '\n'));
	if (!line2)
	{
		free (line);
		return (NULL);
	}
	*j = 0;
	while (b[*i] && b[*i] != '\n')
		line2[(*j)++] = b[(*i)++];
	if (b[*i] == '\n')
		line2[(*j)++] = '\n';
	line2[*j] = '\0';
	return (ft_strjoin(line, line2));
}

char	*ft_my_read(int fd, char *b, int *i, char *line)
{
	int			count;
	int			j;

	count = 1;
	j = ft_strlen(line);
	while (b[*i] != '\n' && count)
	{
		count = read(fd, b, BUFFER_SIZE);
		if (count < 0)
		{
			free (line);
			return (NULL);
		}
		b[count] = '\0';
		*i = 0;
		while (b[(*i) + j] && b[(*i) + j] != '\n')
			j++;
		line = get_line(b, i, &j, line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	static int	i = 0;
	char		*line;

	if (read (fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = check_buf(fd, b, &i);
	if (!line)
		return (NULL);
	ft_strcpy(b, line, &i);
	line = ft_my_read(fd, b, &i, line);
	return (line);
}
