/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:26:29 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/06 19:29:24 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_pxl(t_env *e, int x, int y, unsigned int place)
{
	place = y * (WIDTH * 4);
	place += x * 4;
	if (place < ((WIDTH * HEIGHT) * (sizeof(char) * 4)))
	{
		if (e->inc->z == 0 && e->inc->z2 == 0 && e->inc->z3 == 0)
		{
			e->data[place] = e->colorpix->b;
			e->data[place + 1] = e->colorpix->g;
			e->data[place + 2] = e->colorpix->r;
		}
		else if (e->inc->z <= 0 && e->inc->z2 <= 0 && e->inc->z3 <= 0)
		{
			e->data[place] = e->colorpix->b3;
			e->data[place + 1] = e->colorpix->g3;
			e->data[place + 2] = e->colorpix->r3;
		}
		else
		{
			e->data[place] = e->colorpix->b2;
			e->data[place + 1] = e->colorpix->g2;
			e->data[place + 2] = e->colorpix->r2;
		}
	}
}

void	mlx_color(t_env *e, int x, int y)
{
	unsigned int	place;

	e->colorpix = malloc(sizeof(t_color));
	place = y * (WIDTH * 4);
	place += x * 4;
	e->colorpix->r = (e->color & 0xFF0000) >> 16;
	e->colorpix->g = (e->color & 0xFF00) >> 8;
	e->colorpix->b = (e->color & 0xFF);
	e->colorpix->r2 = (e->color2 & 0xFF0000) >> 16;
	e->colorpix->g2 = (e->color2 & 0xFF00) >> 8;
	e->colorpix->b2 = (e->color2 & 0xFF);
	e->colorpix->r3 = (e->color3 & 0xFF0000) >> 16;
	e->colorpix->g3 = (e->color3 & 0xFF00) >> 8;
	e->colorpix->b3 = (e->color3 & 0xFF);
	
	if (x > 0 && x < WIDTH)
		mlx_pxl(e, x, y, place);
}
