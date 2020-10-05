/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:44:40 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 20:38:59 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (0);
	else if (power > 0)
	{
		result = nb * ft_power(nb, power - 1);
		return (result);
	}
	else
		return (1);
}
