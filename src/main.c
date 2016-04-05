/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:33 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/05 20:03:01 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	text(int i)
{
	if (i == 1)
	{
		ft_putstr("Usage : ./fdf <mapfile.fdf>\n");
		exit (0);
	}
	ft_putstr("WASD : rotations\nUDLR : translate\n -/= : Zoom\n </> : Delta Z\nEchap : Quit program");
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
