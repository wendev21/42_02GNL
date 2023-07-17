/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:56:49 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/07/17 18:38:45 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *join_line(char *line_temp, char *buffer)
{
    char    *joined;

    joined = ft_strjoin(line_temp, buffer);
    free(line_temp);
    return (joined);
}

char	*return_line(char *line_temp)
{
    int     i;
    char    *line;
    i = 0;
    while (line_temp && line_temp[i] != '\n')
    {
        i++;
        if (line_temp[i] == '\0')
            return (line_temp);
    }
    line = ft_substr(line_temp, 0, i + 1);
    free (line_temp);
    return (line);
}

char	*get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    static char *line_temp;
    int         i;
    int         j;
    ssize_t     b_read;

   if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
       return (NULL);
   if ((b_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
       return (NULL);
   if (!line_temp)
   {
       line = return_line(buffer);
       line_temp = ft_substr(buffer, ft_strlen(line), b_read);
   }else
   {
       line_temp = join_line(line_temp, buffer);
       line = return_line(line_temp);
       if((line_temp = ft_substr(line_temp, ft_strlen(line), b_read)) == 0)
           free(line_temp);
   }
    return (line);
}
/*
int main(void)
{
    int fd;

    fd = open("file.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
}

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
*/
