/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_islink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:52:51 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:52:59 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	reads line, counts words separated by '-', if 2 - returns true
*/

#include "../includes/lemin.h"

int	str_islink(char *str)
{
	if (ft_wordnbr(str, '-') == 2)
	{
		if (!ft_strchr(str, ' '))
			return (1);
	}
	return (0);
}
