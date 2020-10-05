/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:44:29 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:26:56 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_vect(t_vect *vect, size_t i)
{
	return ((vect->mem) + i * vect->item_size);
}

void			*ft_vect_add(t_vect *vect, void *data)
{
	return (ft_memcpy(ft_vect(vect, (vect->curlen)++), data, vect->item_size));
}

void			vect_init(t_vect *vect, size_t item_size, size_t init_len)
{
	if (!vect || !item_size || !init_len)
		return ;
	vect->item_size = item_size;
	vect->curlen = 0;
	vect->max_len = init_len;
	if (!(vect->mem = malloc(init_len * item_size)))
		return ;
}

void			vect_delete(t_vect *self)
{
	free(self->mem);
	ft_bzero(self, sizeof(t_vect));
}
