/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:25:08 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:10 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t    ft_strlen(const char *s)
{
    size_t    count;

    count = 0;
    while (s[count])
    {
        if (s[count] != '\0')
            count++;
    }
    return (count);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t    i;
    char    *dst;
    size_t    l1;
    size_t    l2;

    if (!s1 || !s2)
        return (NULL);
    l1 = ft_strlen(s1);
    l2 = ft_strlen(s2);
    i = 0;
    dst = malloc(l1 + l2 + 1);
    if (!dst)
        return (NULL);
    while (i < l1)
    {
        dst[i] = s1[i];
        i++;
    }
    while (i < (l1 + l2 + 1))
    {
        dst[i] = s2[i - l1];
        i++;
    }
	free(s1)
    return (dst);
}



size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char		*dup;
	size_t		i;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char *) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1 && s1[i])
	{
		dup[i] = ((char *)s1)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char		*ft_strjoin_free(char **s1, char *s2)
{
	char	*r;
	char	*c1;
	char	*c2;
	size_t	i;

	if (!(r = (char *)malloc(ft_strlen(*s1) + ft_strlen(s2) + 1)))
		return (NULL);
	c1 = *s1;
	c2 = s2;
	i = 0;
	while (*c1)
		r[i++] = *(c1++);
	while (*c2)
		r[i++] = *(c2++);
	r[i] = '\0';
	free(*s1);
	return (r);
}
