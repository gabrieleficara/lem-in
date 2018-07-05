/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:41:19 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 13:01:23 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../lib/ft_printf/includes/ft_printf.h"

typedef struct	s_rooms
{
	char		*name;
	int			x;
	int			y;
	char		**connection;
	int			ant_n;
	int			check;
}				t_rooms;

typedef struct	s_data
{
	int			start;
	int			end;
	int			ants;
	int			fd;
	int			n_room;
}				t_data;

typedef struct	s_links
{
	char			*l1;
	char			*l2;
	struct s_links	*next;
}				t_links;

typedef struct	s_room
{
	int				ants;
	int				room;
	char			*room2;
	int				x;
	int				y;
	int				visited;
	t_links			*number;
	struct s_room	*next;
}				t_room;

typedef struct	s_infos
{
	int					n_ants;
	char				*line;
	char				*new;
	char				*tmp;
	int					count;
	long long int		far;
	int					k;
	int					a;
	long long int		far2;
	long long int		total;
	int					flag;
	int					plus;
	char				*in_room;
	int					count_link;
	int					**tab;
	char				**l;
	char				*tmp1;
	char				*tmp2;
	int					number_room;
	t_room				end;
	t_room				start;
	t_room				*in;
	int					**xy;
}				t_infos;

int				parsing(char **file);
void			walking_ants(t_list **l, t_room **r, t_infos infos);
t_room			*find_room(t_room **room, char *infos);
void			freelinks(t_links **tmp);
void			freed(t_room **tmp);
void			freedoom(char **as);
void			delfun(void *str, size_t num);
char			*name_room(char *s);
void			addroom(t_room **room, int nb, char *tmp);
void			addlink(t_room *room, char *l3, char *l4);
t_list			*short_road(t_infos *infos, t_room *room);
void			placing_x_y(t_room *nb, char *new, char *tmp);
void			read_array(t_infos *infos, char *file);
void			start_and_end(t_infos *infos, char **line, char **new, int *j);
t_room			*liste(t_infos *infos, t_room *nb, char *new);
int				count_list(t_list *final);
int				count_list(t_list *final);
int				linkstr(char *str, char *file, int *error);
int				checkse(char **str, t_data *data, int *flag, int i);
int				error(char **str);
int				noants(char **str, int fd, int flag, int *i);
int				b_obt(char **file, t_data *data, int *i, int *flag);
int				repeated(char *str, char *file);
int				coor_check(char *str, char *file);

#endif
