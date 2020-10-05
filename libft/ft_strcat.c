/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:40:01 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 20:42:31 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return (s1);
}
