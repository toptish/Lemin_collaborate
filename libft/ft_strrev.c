/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:28:04 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 20:45:04 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_s_rev(char *src)
{
	char	*dst;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (src[k])
		k++;
	if (!(dst = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	while (--k >= 0)
		dst[i++] = src[k];
	dst[i] = '\0';
	return (dst);
}
