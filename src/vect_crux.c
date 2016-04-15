/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_crux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:47:15 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/15 19:47:12 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		crux_x(int x1, int y1, int x2, t_env *c)
{
	int dx;

	dx = x2 - x1;
	if (dx > 0)
	{
		while (x1 != x2)
		{
			mlx_color(c, x1, y1);
			x1++;
		}
	}
	else
	{
		while (x1 != x2)
		{
			mlx_color(c, x1, y1);
			x1--;
		}
	}
}

static void		crux_y(int x1, int y1, int y2, t_env *c)
{
	int dy;

	dy = y2 - y1;
	if (dy > 0)
	{
		while (y1 != y2)
		{
			mlx_color(c, x1, y1);
			y1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			mlx_color(c, x1, y1);
			y1--;
		}
	}
}

void			crux(t_box *b, t_env *c)
{
	int dx;
	int dy;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	if (dy == 0)
		crux_x(b->x1, b->y1, b->x2, c);
	if (dx == 0)
		crux_y(b->x1, b->y1, b->y2, c);
}
