#include "get_next_line_bonus.h"
#include "stdio.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	max;
	char			*sub;

	if (!s)
		return (NULL);
	max = len;
	if ((int)(ft_strlen((char *)s) - start) < (int)max)
		max = (int)(ft_strlen((char *)s)) - start;
	if ((int) max < 0)
		max = 0;
	if (max == 0)
		return (NULL);
	sub = malloc((max + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)s + start, max + 1);
	return (sub);
}

char	*ft_read_nl(int fd, ssize_t size)
{
	t_rd			r;

	r.fc = malloc(sizeof(char) * 1);
	if (r.fc)
		r.fc[0] = 0;
	while (r.fc)
	{
		r.tmp = malloc(sizeof(char) * (size + 1));
		if (!r.tmp)
			break ;
		r.rd = read(fd, r.tmp, size);
		if (r.rd == -1)
			break ;
		r.tmp[r.rd] = 0;
		r.fc = ft_strjoin(r.fc, r.tmp);
		if (!r.fc || r.rd < size || ft_strchr(r.fc, '\n'))
			break ;
	}
	if (r.tmp && r.rd < 0)
		free(r.tmp);
	if (r.rd >= 0)
		return (r.fc);
	if (r.fc)
		free(r.fc);
	return (NULL);
}

char	*ft_ls_last(t_ls **ls, int fd)
{
	char	*ct;
	t_ls	*last;

	last = *ls;
	if (!last)
		return (NULL);
	if (last->fd == fd)
	{
		ct = last->ct;
		free(last);
		*ls = NULL;
		return (ct);
	}	
	return (ft_ls_last(&(last->nt), fd));
}

char	*ft_ls_new(t_ls **ls, int fd, char *fc)
{
	t_ls	*last;
	char	*nl;
	char	*ret;

	nl = ft_strchr(fc, '\n');
	if (nl)
	{
		last = malloc(sizeof(t_ls));
		last->fd = fd;
		last->ct = ft_substr(fc, nl - fc + 1, ft_strlen(fc));
		last->nt = *ls;
		*ls = last;
		ret = ft_substr(fc, 0, nl - fc + 1);
		free(fc);
		return (ret);
	}
	ret = ft_substr(fc, 0, ft_strlen(fc));
	free(fc);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*fc;
	static t_ls	*ls;

	if (BUFFER_SIZE == 0)
		return (NULL);
	ret = NULL;
	fc = ft_read_nl(fd, BUFFER_SIZE);
	fc = ft_strjoin(ft_ls_last(&ls, fd), fc);
	if (!fc)
		return (NULL);
	return (ft_ls_new(&ls, fd, fc));
}
