/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:24:17 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/24 17:26:22 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*find_fd(t_file **start, int fd)
{
	t_file	*prec;
	t_file	*tmp;

	if (*start)
	{
		if ((*start)->fd == fd)
		{
			tmp = *start;
			*start = (*start)->next;
			return (tmp);
		}
		prec = *start;
		while (prec->next)
		{
			if (prec->next->fd == fd)
			{
				tmp = prec->next;
				prec->next = tmp->next;
				return (tmp);
			}
			prec = prec->next;
		}
	}
	return (NULL);
}

int		read_file(t_file **start, char *buf, int fd)
{
	t_file	*tmp;
	int		len;

	if ((len = read(fd, buf, 0)) != 0)
	{
		if ((tmp = find_fd(start, fd)))
		{
			free(tmp->buf);
			free(tmp);
		}
		return (len);
	}
	if ((tmp = find_fd(start, fd)))
	{
		buf = ft_strcpy(buf, tmp->buf);
		free(tmp->buf);
		free(tmp);
		return (ft_strlen(buf));
	}
	len = read(fd, buf, BUFFER_SIZE);
	buf[len] = '\0';
	return (len);
}

void	keep_line(t_file **start, int fd, char *end_buf)
{
	t_file	*new;

	if (*end_buf)
	{
		if (!(new = malloc(sizeof(t_file))))
			return ;
		new->fd = fd;
		if (!(new->buf = ft_strdup(end_buf)))
			return ;
		new->next = *start;
		*start = new;
	}
}

int		get_next_line(int fd, char **line)
{
	static t_file	*start = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				i;
	int				len;
	int				join;

	if (fd < 0 || !line)
		return (-1);
	join = 0;
	while ((len = read_file(&start, buf, fd)) > 0)
	{
		i = 0;
		while (i < len && buf[i] != '\n')
			i++;
		if (buf[i] == '\n' && !(buf[i] = '\0'))
			keep_line(&start, fd, buf + i + 1);
		*line = (join) ? ft_strjoin_free(line, buf) : ft_strdup(buf);
		join = 1;
		if (i < len)
			return (1);
	}
	if (!(*line))
		*line = ft_strdup("");
	return (len);
}
