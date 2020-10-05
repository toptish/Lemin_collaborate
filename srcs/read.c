/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:44:59 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 09:41:23 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static char	*char_valid(t_lem *lemin, char *str)
{
	int s;

	s = -1;
	while (str[++s])
	{
		if (str[s] < 0)
		{
			free(str);
			ft_error(lemin, INVDCHAR);
		}
	}
	return (str);
}

static char	**l_join(char *str)
{
	char	**temp;
	int		s;

	if (!str)
		return (NULL);
	s = ft_wordnbr(str, '\n');
	if (!(temp = malloc(sizeof(char *) * (s + 1))))
		return (NULL);
	s = 0;
	while (str && *str)
	{
		temp[s] = str;
		if ((str = ft_strchr(str, '\n')))
			*str = '\0';
		if (str && *(str + 1) && *(str + 1) != '\0')
			str += 1;
		s++;
	}
	temp[s] = NULL;
	return (temp);
}

char		**l_read(t_lem *lemin)
{
	char	str[BUF_SIZE + 1];
	char	*str_a;
	char	*str_b;
	int		red;

	str_a = NULL;
	ft_bzero(str, sizeof(char) * (BUF_SIZE + 1));
	if ((red = read(STDIN_FILENO, str, BUF_SIZE)) <= 0)
		ft_error(lemin, EMPTYFILE);
	str[red] = '\0';
	if ((str_a = ft_strdup(str)) == NULL)
		return (NULL);
	while ((red = read(STDIN_FILENO, str, BUF_SIZE)) > 0)
	{
		str[red] = '\0';
		str_b = str_a;
		str_a = ft_strjoin(str_b, str);
		free(str_b);
		if (str_a == NULL)
			return (NULL);
	}
	if (str_isempty(str_a, BUF_SIZE + 1))
		ft_error(lemin, EMPTYLINE);
	char_valid(lemin, str_a);
	return (l_join(str_a));
}
