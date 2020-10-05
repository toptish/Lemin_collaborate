/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:30:52 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:36:22 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(char ***argv)
{
	int i;
	int j;

	if (!(argv) || !(*argv))
		return ;
	i = 0;
	while ((*argv)[i] != NULL)
	{
		j = 0;
		if (!(*argv)[i])
			return ;
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}
