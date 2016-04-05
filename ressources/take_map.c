/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:31:41 by pmartine          #+#    #+#             */
/*   Updated: 2016/03/06 15:31:43 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	ft_verif_map(char **positions)
{
	(void)positions;
	return (1);
}

t_map	*take_map(char *argv, t_map *map)
{
	int	i;
	int	j;
	int	fd;
	char	**positions;
	char	*line;
	
	i = 0;
	j = 0;
	positions = NULL;
	line = NULL;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		i = 0;
		positions = ft_strsplit(line, ' ');
		if (ft_verif_map(positions) == 1)
			while (positions[i++])
			{	
				map->z[i] = ft_atoi(positions[i]);
				map->x[i] = i;
				map->y[i] = j;
			}
		else
		{
			free(positions);
			free(line);
			return (NULL);
		}
		j++;
		free(positions);
		free(line);
	}
	return (map);
}
