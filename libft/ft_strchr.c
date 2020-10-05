/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:17:32 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 20:42:39 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *temp;

	temp = (char *)s;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
