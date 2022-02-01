/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:55:48 by bbourcy           #+#    #+#             */
/*   Updated: 2022/02/01 16:35:52 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

//gnl_utlis
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strchr_i(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//gnl
char	*ft_shrink_buffer(char *buf, char *line);
char	*ft_expand_buffer(char *buf, int fd);
char	*ft_newread(int fd);
char	*get_next_line(int fd);

#endif
