/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:59:59 by bbourcy           #+#    #+#             */
/*   Updated: 2022/02/01 16:38:07 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retourne la longueur de la string
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

//Alloue assez de memoire (longueur de len) pour faire une copie depuis start
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		dst = malloc (0);
		*dst = '\0';
		return (dst);
	}
	else if (len < (ft_strlen(s) + 1 - start))
		dst = malloc(len + 1);
	else
		dst = malloc (ft_strlen(s) + 1 - start);
	if (!dst)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

//copie de la src vers dest avec \0
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			size_src;

	i = 0;
	if (src == NULL)
		return (0);
	size_src = ft_strlen(src);
	if ((int)size < 0)
		size = size_src + 1;
	if (size >= 2 && size_src != 0)
	{
		while (i < size - 1)
		{
			if (i < size_src)
				dst[i] = src[i];
			else if (i == size_src)
				dst[i] = '\0';
			i++;
		}
	}
	if (size != 0)
		dst[i] = '\0';
	return (size_src);
}

//recherche le premier caractere d une nouvelle string
int	ft_strchr_i(const char *s, int c)
{
	unsigned char	c_unsigned;
	int				i;

	i = ft_strlen(s) - BUFFER_SIZE;
	if (i < 0)
		i = 0;
	if (!s)
		return (-1);
	c_unsigned = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c_unsigned)
			return (i);
		i++;
	}
	return (-1);
}

//concatener 2 string avec une limite de x caracteres
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sizedst;
	size_t	sizesrc;

	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (dstsize == 0 || sizedst >= dstsize)
		return (sizesrc + dstsize);
	while (*dst != '\0' && --dstsize > 0)
		dst++;
	while (*src != '\0' && --dstsize > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (sizedst + sizesrc);
}
