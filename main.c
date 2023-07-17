/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:30:00 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/07/10 21:09:50 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
/*
int main(void)
{
	int	fd;
	static int	i;
	char	buffer[BUFFER_SIZE];
	ssize_t	b_read;


	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	//printf("%d\n", fd);
	b_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (b_read == -1)
		return(printf("no hay nada que leer"), 0);
	buffer[b_read] = '\0';

	//printf("Datos leidos del archivo : \n%s\n", buffer);

	i = 0;
	while (i < b_read && buffer[i] != '\n')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	
	if(close(fd) == -1)
	{
		perror("ERROR al Cerrar el archivo");
	}


	return (0);
}*/
