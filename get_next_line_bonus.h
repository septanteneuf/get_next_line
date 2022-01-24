/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaccard <asaccard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:56:34 by asaccard          #+#    #+#             */
/*   Updated: 2021/11/12 04:17:18 by asaccard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ls
{
	int				fd;
	char			*ct;
	struct s_ls		*nt;
}	t_ls;

typedef struct s_rd
{
	int		rd;
	char	*tmp;
	char	*fc;
}	t_rd;

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*get_next_line(int fd);
char			*ft_strchr(char *str, int c);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(char *str);

#endif