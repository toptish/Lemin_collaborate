/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_one_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:14:28 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:34:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_where_n(char *s)
{
	int			i;

	i = 0;
	if (s[0] == '\n')
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int			ft_give_line(char *str, char **line)
{
	char		*tmp;
	int			num_n;

	num_n = ft_where_n(str);
	if (str[num_n] == '\0' || str[num_n + 1] == '\0')
	{
		*line = ft_strsub(str, 0, num_n);
		free(str);
		str = NULL;
		return (1);
	}
	*line = ft_strsub(str, 0, num_n);
	tmp = ft_strdup(str + (num_n + 1));
	ft_strdel(&str);
	str = tmp;
	return (1);
}

int					gnl_one_desc(const int fd, char **line)
{
	size_t		ret;
	static char	*s;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		if (s == NULL)
			s = ft_strnew(1);
		tmp = ft_strjoin(s, buf);
		free(s);
		s = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == 0 && s == NULL)
		return (0);
	return (ft_give_line(s, line));
}
