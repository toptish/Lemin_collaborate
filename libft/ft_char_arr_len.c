/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_arr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:29:51 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:36:40 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_arr_len(char **arr)
{
	size_t len;

	len = 0;
	if (!*arr || !arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}
