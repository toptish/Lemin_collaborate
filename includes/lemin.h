/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:38:27 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdint.h>

# define OHELP			(1 << 0)
# define OPT_L			(1 << 1)
# define OPT_E			(1 << 2)
# define OPT_W			(1 << 3)
# define OPT_F			(1 << 4)
# define ERR			(0)

# define EMPTYFILE		(1)
# define LINKERROR		(2)
# define NOWAYS			(3)
# define DUPCOMM		(4)
# define DUPROOM		(5)
# define LINEERROR		(6)
# define ANTSERROR		(7)
# define NOTSRCSINK		(8)
# define NOARG			(9)
# define EMPTYLINE		(10)
# define DUPCOORD		(11)
# define ANTOVERFLOW	(12)
# define INVDCHAR		(13)

# define SET			(1)
# define DEL			(0)
# define INCREASE		(1)
# define DECREASE		(-1)
# define START			(14)
# define END			(15)
# define SIZE			(16384)
# define MAX_ANTS		(99999)
# define BUF_SIZE 		8192

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				id;
	int				ant;
	int				vol;
	int				prev;
	int				start;
	int				in_way;
	struct s_node	*next;
}					t_node;

typedef struct		s_rms
{
	t_node			*head;
	t_node			*start;
	t_node			*end;
	int				all;
	int				r;
}					t_rms;

typedef struct		s_lnk
{
	int				*marked;
	t_node			**neighbor;
}					t_lnk;

typedef struct		s_way
{
	int				s_t;
	int				len;
	int				stream;
	t_node			*node[256];
}					t_way;

typedef struct		s_que
{
	t_node			*units[SIZE];
	int				back;
	int				front;
}					t_que;

typedef struct		s_lem
{
	int				c;
	int				opc;
	int				ants;
	int				size;
	int				start;
	int				final;
	int				*parent;
	char			**str;
	int				rid;
	t_rms			*rooms;
	t_lnk			*links;
	t_node			**node;
	t_way			**ways;
	t_que			*queue;

}					t_lem;

void				ft_error(t_lem *lemin, int code);
void				l_init(t_lem *lemin);
char				**l_read(t_lem *lemin);
int					read_ants(t_lem *lemin, char **str);
t_rms				*read_rooms(t_lem *lemin, char **str);
t_lnk				*read_links(t_lem *lemin, char **str);
int					str_isant(char *str);
int					str_isroom(char *str);
int					str_islink(char *str);
int					str_iscommand(char *str);
int					str_isempty(char *str, int size);
void				ways_get(t_lem *lemin);
void				set_atr(t_lem *lemin, t_way **ways);
void				set_vol(t_lem *lemin, t_node *src, \
											t_node *dst, int set);
void				regraph(t_lem *lemin, t_way *ways, int set);
void				way_sort(t_way **ways);
t_way				*srch_way(t_lem *lemin, t_node *src);
void				rst_graph(t_lem *lemin);
int					chk_stream(t_way **ways, int ants);
void				l_move(t_lem *lemin);
void				links_free(t_lnk *links, int size);
void				rooms_free(t_rms *rooms);
void				ways_free(t_way **ways);
void				lemin_free(t_lem *lemin);
int					input_arg(t_lem *lemin, char **str);
void				output_arg(t_lem *lemin);
int					output_usage(char *prg);

#endif
