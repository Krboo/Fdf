/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:33 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/06 19:28:15 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	text(int i)
{
	if (i == 1)
	{
		ft_putstr("Usage : ./fdf <mapfile.fdf>\n");
		exit(0);
	}
	ft_putstr("Up/Down/Left/Right : translation + rotation\n \
	Mouse click : center map + zoom\n+/- : increase / decrease Z\n \
	Q / W : bigger zoom / dezoom\nEchap : quit program");
}

int			main(int ac, char **av)
{
	t_map *map;
	t_env *e;

	text(ac);
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
	return (0);
}
