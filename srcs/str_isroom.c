/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isroom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:45:45 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:46:11 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	reads line, counts words separated by ' '
**	and checks that coords are numbers
*/

int	str_isroom(char *str)
{
	char *s;

	if (ft_wordnbr(str, ' ') == 3)
	{
		if (*str == 'L' || ft_strchr(str, '-'))
			return (0);
		s = ft_strchr(str, ' ') + 1;
		while (ft_isdigit(*s) || *s == ' ' || *s == '\t')
			s++;
		if (*s == '\0')
			return (1);
	}
	return (0);
}
