/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:54:34 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:33 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_file
{
	char			*buf;
	int				fd;
	struct s_file	*next;
}						t_file;

size_t			ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin_free(char **s1, char *s2);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);

#endif
