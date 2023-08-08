/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:59:05 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/08/08 16:51:12 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*read_stash(char *line_temp, int fd)
{
	ssize_t	b_read;
	char	*buffer;
	char	*temp;

	temp = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		temp = line_temp;
		line_temp = ft_strjoin(line_temp, buffer);
		free(temp);
		if (!line_temp)
			return (free(buffer), free(line_temp), NULL);
		if (ft_strchr(line_temp, '\n') != -1)
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line_temp);
}

char	*return_line_sec(char *line_temp, int i, char *line)
{
	int	len;

	len = i;
	if (line_temp[i] == '\n')
	len += 1;
	line = ft_substr(line_temp, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*return_line(char **line_temp)
{
	int		i;
	char	*line;
	char	*aux;
	size_t	len_lt;

	line = NULL;
	aux = NULL;
	len_lt = ft_strlen(*line_temp);
	if ((*line_temp) == NULL)
		return (NULL);
	i = 0;
	while ((*line_temp)[i] != '\0' && (*line_temp)[i] != '\n')
		i++;
	line = return_line_sec(*line_temp, i, line);
	if (!line)
		return (free(*line_temp), *line_temp = NULL, NULL);
	if ((len_lt - i) > 0 && (len_lt - i - 1) > 0)
	{
		aux = ft_substr(*line_temp, i + 1, (len_lt - i - 1));
		if (!aux)
			return (free(*line_temp), NULL);
	}
	free (*line_temp);
	*line_temp = aux;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	*line_temp[1024];

	linea = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0) || fd > FOPEN_MAX)
	{
		if (line_temp[fd])
			(free(line_temp[fd]), line_temp[fd] = NULL);
		return (NULL);
	}
	if (ft_strchr(line_temp[fd], '\n'))
		line_temp[fd] = read_stash(line_temp[fd], fd);
	linea = return_line(&line_temp[fd]);
	return (linea);
}
