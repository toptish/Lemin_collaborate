/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:31:28 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 20:34:42 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(char *s)
{
	char *temp1;
	char *temp2;

	temp1 = ft_itoa(ft_atoi(s));
	temp2 = ft_itoa_sign(ft_atoi(s));
	if ((ft_strcmp(temp1, s) == 0) || ft_strcmp(temp2, s) == 0)
	{
		free(temp1);
		free(temp2);
		return (1);
	}
	free(temp1);
	free(temp2);
	return (0);
}
