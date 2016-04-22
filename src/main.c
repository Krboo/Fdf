/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:33 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/22 16:28:24 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display(t_env *e)
{
	char	*commands;

	commands = "fleches : rotations";
	mlx_string_put(e->mlx, e->win, 5, 5, 0xFBFBFB, commands);
	commands = "souris : deplacer la map";
	mlx_string_put(e->mlx, e->win, 5, 20, 0xFBFBFB, commands);
	commands = "+/- : zoomer / dezoomer";
	mlx_string_put(e->mlx, e->win, 5, 35, 0xFBFBFB, commands);
	commands = "pageup/pagedown : +/- Z";
	mlx_string_put(e->mlx, e->win, 5, 50, 0xFBFBFB, commands);
	commands = "clear : reset";
	mlx_string_put(e->mlx, e->win, 5, 65, 0xFBFBFB, commands);
	commands = "echap : quitter";
	mlx_string_put(e->mlx, e->win, 5, 80, 0xFBFBFB, commands);
}

void	free_all(t_env *e, t_map *map)
{
	free(map);
	free(e);
}

void	str_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		main(int ac, char **av)
{
	t_map *map;
	t_env *e;

	if (ac != 2 || ft_strcmp(av[1], "/dev/null") == 0 || \
	ft_strncmp(av[1], "/dev", 4) == 0)
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
	free_all(e, map);
	return (0);
}
