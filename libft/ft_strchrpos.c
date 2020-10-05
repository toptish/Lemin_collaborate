/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:28:04 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 20:42:48 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strchrpos(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (0);
}
