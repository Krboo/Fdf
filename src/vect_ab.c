/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:57 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/06 18:39:55 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	vect_ab(t_box *b, t_env *c)
{
	int dx;
	int dy;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	if (dx == 0 || dy == 0)
		crux(b, c);
	if (dx > 0 && dy > 0 && dx >= dy)
		octant_1(b, c);
	if (dx > 0 && dy > 0 && dx < dy)
		octant_2(b, c);
	if (dx < 0 && dy > 0 && -dx < dy)
		octant_3(b, c);
	if (dx < 0 && dy > 0 && -dx >= dy)
		octant_4(b, c);
	if (dx < 0 && dy < 0 && dx <= dy)
		octant_5(b, c);
	if (dx < 0 && dy < 0 && dx > dy)
		octant_6(b, c);
	if (dx > 0 && dy < 0 && dx < -dy)
		octant_7(b, c);
	if (dx > 0 && dy < 0 && dx >= -dy)
		octant_8(b, c);
}
