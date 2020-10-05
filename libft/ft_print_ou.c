/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:00:37 by rmarni            #+#    #+#             */
/*   Updated: 2020/10/03 20:40:50 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_zero_ou(void)
{
	if (ft_check_is_flag('#'))
	{
		g_pfstr.sizeof_num = 1;
		ft_prep_conv();
		return (ft_display_string("0"));
	}
	return (ft_simple_zero());
}

void		ft_type_convert_ou(unsigned long *num)
{
	if (g_pfstr.type_mod[0] == '0')
		*num = (unsigned int)*num;
	if (g_pfstr.type_mod[0] == 'h')
		*num = (unsigned short)*num;
	if (g_pfstr.type_mod[0] == 'h' && g_pfstr.type_mod[1] == 'h')
		*num = (unsigned char)*num;
}

void		ft_print_ou(unsigned long num)
{
	ft_type_convert_ou(&num);
	if (g_pfstr.precision == 0)
	{
		ft_del_flag(' ');
		ft_del_flag('0');
	}
	ft_del_flag('+');
	if (g_pfstr.type_conv == 'u')
		ft_del_flag(' ');
	if (ft_check_is_flag('-'))
		ft_del_flag(' ');
	if (num == 0)
		return (ft_zero_ou());
	if (g_pfstr.type_conv == 'o')
		ft_itoa_base(num, 8);
	else if (g_pfstr.type_conv == 'u')
		ft_itoa_base(num, 10);
	ft_prep_conv();
	ft_display_string(g_pfstr.arr_num);
	return ;
}
