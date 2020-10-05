/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:57:46 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 20:46:39 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_wordnbr(char const *s, char c)
{
	size_t i;
	size_t o;

	i = 0;
	o = 0;
	while (s[i])
	{
		if (s[i] != c)
			o++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (o);
}
