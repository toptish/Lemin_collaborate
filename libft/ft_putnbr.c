/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:35:45 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 20:41:55 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_divide(int n)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
			ft_putchar(-1 * n + '0');
		else
			ft_putchar(n + '0');
	}
	else
	{
		ft_divide(n / 10);
		ft_divide(n % 10);
	}
}

void		ft_putnbr(int n)
{
	if (n >= 0)
		ft_divide(n);
	else
	{
		ft_putchar('-');
		ft_divide(n);
	}
}
