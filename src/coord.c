/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:45:48 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/06 17:24:28 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_get_tab(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->y = 0;
	i = 0;
	if ((fd = open(map->av[1], O_RDONLY)) < 0)
	{
		ft_putendl("map cannot be read");
		exit(0);
	}
	while (get_next_line(fd, &line))
		map->y++;
	close(fd);
	fd = open(map->av[1], O_RDONLY);
	if ((map->tab = (char **)malloc(sizeof(char *) * (map->y + 1))) == NULL)
		exit(0);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			map->tab[i++] = line;
		else
			map->y--;
	}
	close(fd);
}

t_coord		*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_coord *coord;

	if ((coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	coord->size_x = (map->x);
	coord->size_y = (map->y);
	coord->z = z;
	coord->x = x - coord->size_x / 2;
	coord->y = y - map->y / 2;
	return (coord);
}

void		get(int i, int j, t_map *map, t_coord ***coord)
{
	while (++j < map->x)
	{
		if (map->tmp[j] != '\0' && map->tmp[j][0] != '\n')
		{
			coord[i][j] = ft_new_coord(j, i, ft_atoi(map->tmp[j]), map);
			coord[i][j]->size_y = (map->y);
		}
	}
	free(map->tmp);
}

t_coord		***ft_get_coord(t_map *map)
{
	int		i;
	int		j;
	t_coord	***coord;

	i = 0;
	ft_get_tab(map);
	if ((coord = (t_coord ***)malloc(sizeof(t_coord **) * map->y + 1)) == NULL)
		return (NULL);
	while (i < map->y)
	{
		map->tmp = ft_strsplit(map->tab[i], ' ');
		map->x = 0;
		while (map->tmp[map->x] != '\0')
			map->x++;
		j = -1;
		if ((coord[i] = (t_coord **)malloc(sizeof(t_coord*) *
(map->x + 1))) == NULL)
			return (NULL);
		get(i, j, map, coord);
		i++;
	}
	map->tmp = NULL;
	return (coord);
}
