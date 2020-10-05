/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 19:54:39 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:28:11 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_print_binary(unsigned int num)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		ft_printf("%u", (num >> i) & 1);
		i--;
	}
}
