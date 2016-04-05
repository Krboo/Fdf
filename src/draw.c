/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:06 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/05 19:54:49 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_calc_pixel(t_env *e, int i, int j)
{
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->z3 = e->coord[i + 1][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->y2 = (e->coord[i + 1][j]->y * INC);
	else
		e->inc->y2 = (e->coord[i][j]->y * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->x2 = (e->coord[i][j + 1]->x * INC);
	else
		e->inc->x2 = (e->coord[i][j]->x * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z = e->coord[i][j]->z * e->zh;
	e->inc->x1 = (e->coord[i][j]->x * INC);
	e->inc->y1 = (e->coord[i][j]->y * INC);
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
}

void	ft_put_pixel(t_env *e, int i, int j)
{
	ft_calc_pixel(e, i, j);
	e->box->x1 = XA + OFF;
	e->box->y1 = YA + YOFF;
	e->box->x2 = XB + OFF;
	e->box->y2 = YB + YOFF;
	e->inc->z3 = 0;
	vect_ab(e->box, e);
	if (e->coord[0][0]->size_y > 1)
	{
		ft_calc_pixel(e, i, j);
		e->box->x1 = XA + OFF;
		e->box->y1 = YA + YOFF;
		e->box->x2 = XC + OFF;
		e->box->y2 = YC + YOFF;
		e->inc->z2 = 0;
		vect_ab(e->box, e);
	}
}

void	draw(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((e->inc = malloc(sizeof(t_inc))) == NULL)
		exit(0);
	if ((e->box = malloc(sizeof(t_box))) == NULL)
		exit(0);
	while (i < e->coord[0][0]->size_y)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x)
		{
			ft_put_pixel(e, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
