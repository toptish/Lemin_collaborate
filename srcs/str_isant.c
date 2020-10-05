/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:53:49 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:53:59 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	reads line validates if it is number
*/

int	str_isant(char *str)
{
	int n;

	n = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (str[n] == '+')
		str++;
	while (str[n])
	{
		if (!ft_isdigit(str[n]))
			return (0);
		n++;
	}
	return (n);
}
