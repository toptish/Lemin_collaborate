/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isempty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:50:08 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:50:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	str_isempty(char *str, int size)
{
	int i;

	i = 0;
	if (str[i] == 10)
		return (EMPTYLINE);
	while (i < size && str[i])
	{
		if (str[i] == 10 && str[i + 1] == 10)
			return (EMPTYLINE);
		i++;
	}
	return (0);
}
