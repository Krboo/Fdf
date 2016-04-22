/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_octant2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:35:19 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/06 19:33:15 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	octant_5(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		mlx_color(c, b->x1, b->y1);
		e = e - dy;
		if (e >= 0)
		{
			b->y1--;
			e = e + dx;
		}
		b->x1--;
	}
}

void	octant_6(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		mlx_color(c, b->x1, b->y1);
		e = e - dx;
		if (e >= 0)
		{
			b->x1--;
			e = e + dy;
		}
		b->y1--;
	}
}

void	octant_7(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		mlx_color(c, b->x1, b->y1);
		e = e + dx;
		if (e > 0)
		{
			b->x1++;
			e = e + dy;
		}
		b->y1--;
	}
}

void	octant_8(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		mlx_color(c, b->x1, b->y1);
		e = e + dy;
		if (e < 0)
		{
			b->y1--;
			e = e + dx;
		}
		b->x1++;
	}
}
