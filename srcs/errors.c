/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:43:57 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	generates an error structure and returns an error description
**  for a given error code
*/

static char		*error_type(int code)
{
	static char	*error[] = {
		[ERR] = "\e[91mERROR: ",
		[EMPTYFILE] = "Empty file\e[0m",
		[LINKERROR] = "Link error\e[0m",
		[NOWAYS] = "No ways\e[0m",
		[DUPCOMM] = "Duplicate command\e[0m",
		[DUPROOM] = "Duplicate room\e[0m",
		[LINEERROR] = "Line error\e[0m",
		[ANTSERROR] = "Ants input error\e[0m",
		[NOTSRCSINK] = "Start or end room is missing\e[0m",
		[NOARG] = "Missing arguments\e[0m",
		[EMPTYLINE] = "Empty line\e[0m",
		[DUPCOORD] = "Duplicate coordinates\e[0m",
		[ANTOVERFLOW] = "Too many ants. Check lemin.h to change MAX ANTS\e[0m",
		[INVDCHAR] = "Invalid character\e[0m"
	};

	return (error[code]);
}

/*
**	if error exists returns error or detailed error depending on program mode
**	-e option for detailed error description
*/

void			ft_error(t_lem *lemin, int code)
{
	lemin_free(lemin);
	if (code != ERR)
	{
		if (lemin->opc & OPT_E)
		{
			ft_putstr_fd(error_type(0), STDERR_FILENO);
			ft_putendl_fd(error_type(code), STDERR_FILENO);
		}
		else
			ft_putendl_fd("ERROR", STDERR_FILENO);
	}
	else
	{
		ft_printf("PERROR");
		perror("ERROR");
	}
	exit(EXIT_FAILURE);
}
