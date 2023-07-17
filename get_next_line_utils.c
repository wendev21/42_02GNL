/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:33:17 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/07/13 19:14:14 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

    if (!str)
        return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	cc;

	str = ((char *)s);
	cc = (char)c;
	while (*str != cc)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = ft_strlen((char *)src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	l_s1;

	l_s1 = ft_strlen(s1) + 1;
	ptr = (char *)malloc(l_s1 * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, l_s1);
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*result;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		start = ft_strlen(s);
	}
	len_s = ft_strlen(s + start);
	if (len > len_s)
		len = len_s;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	j = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	if (s1 != 0)
		ft_strlcpy(str, s1, (j + 1));
	i = 0;
	while (s2[i])
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
