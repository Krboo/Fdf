/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:33 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/15 19:37:36 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	str_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		main(int ac, char **av)
{
	t_map *map;
	t_env *e;

	if (ac == 1)
		str_exit("Usage : ./fdf <mapfile.fdf>");
	e = (t_env *)malloc(sizeof(t_env));
	map = (t_map *)malloc(sizeof(t_map));
	e->off = XCENTER;
	e->off2 = YCENTER;
	e->zoom = 42;
	e->zh = 1;
	e->rot = 0;
	e->roty = M_PI / 2;
	map->av = av;
	e->coord = ft_get_coord(map);
	ft_mlx(e);
	free(e);
	free(map);
	return (0);
}
