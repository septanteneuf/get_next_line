/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaccard <asaccard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:34:03 by asaccard          #+#    #+#             */
/*   Updated: 2021/11/12 04:13:53 by asaccard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdio.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1)
	{
		if (src[i])
			dest[i] = src[i];
		else
			break ;
		i++;
	}
	dest[i++] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strchr(char *str, int c)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	char			*start;
	char			*end;

	i = 0;
	start = dest;
	end = src;
	while (start[i] && i < size && size > 0)
		i++;
	start = dest + i;
	while (*end)
		end++;
	i = 0;
	while (src[i] && i + (start - dest) < size - 1 && size > 0)
	{
		start[i] = src[i];
		i++;
	}
	if (start - dest != size)
		start[i] = '\0';
	return ((end - src) + (start - dest));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *) malloc((length + 1) * sizeof(char));
	str[0] = 0;
	if (!str)
		return (NULL);
	ft_strlcat(str, (char *)s1, length + 1);
	ft_strlcat(str, (char *)s2, length + 1);
	free((void *)s1);
	free((void *)s2);
	return (str);
}
