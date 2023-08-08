/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:59:05 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/08/05 22:38:07 by wecorzo-         ###   ########.fr       */
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
		return (free(buffer), NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		temp = line_temp;
		line_temp = ft_strjoin(line_temp, buffer);
		free(temp);
		if (ft_strchr(line_temp, '\n') != -1)
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line_temp);
}

char	*return_line(char **line_temp)
{
	int		i;
	char	*line;
	char	*aux;

	line = NULL;
	aux = NULL;
	if ((*line_temp) == NULL)
		return (NULL);
	i = 0;
	while ((*line_temp)[i] != '\0' && (*line_temp)[i] != '\n')
		i++;
	if ((*line_temp)[i] == '\n')
		line = ft_substr((*line_temp), 0, i + 1);
	else
		line = ft_substr(*line_temp, 0, i);
	if ((ft_strlen(*line_temp) - i) > 0 && (ft_strlen(*line_temp) - i - 1) > 0)
		aux = ft_substr(*line_temp, i + 1, (ft_strlen(*line_temp) - i - 1));
	free (*line_temp);
	*line_temp = aux;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line_temp;
	char		*linea;

	linea = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (ft_strchr(line_temp, '\n'))
		line_temp = read_stash(line_temp, fd);
	linea = return_line(&line_temp);
	return (linea);
}
