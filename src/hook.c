/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:24 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/16 19:33:46 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	loop_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	draw(e);
	display(e);
	return (0);
}

static void	reset(t_env *c)
{
	c->zoom = 42;
	c->rot = 90;
	c->roty = -88;
	c->zh = -2;
}

static int	mouse_hook(int button, int x, int y, t_env *c)
{
	if (button == 1)
	{
		c->off = x;
		c->off2 = y;
	}
	if (button == 2)
	{
		c->off = x;
		c->off2 = y;
	}
	loop_hook(c);
	return (0);
}

static int	key_hook(int keycode, t_env *e)
{
	if (keycode == ECHAP)
		exit(0);
	if (keycode == RESET)
		reset(e);
	if (keycode == Z_PLUS)
		e->zh += 1.5;
	if (keycode == Z_MINE)
		e->zh -= 1.5;
	if (keycode == ZOOM)
		e->zoom += 3;
	if (keycode == DEZOOM)
		e->zoom -= (e->zoom >= 3) ? 3 : 0;
	if (keycode == UP)
		e->rot += (5 * (M_PI / 180));
	if (keycode == DOWN)
		e->rot -= (5 * (M_PI / 180));
	if (keycode == LEFT)
		e->roty += (5 * (M_PI / 90));
	if (keycode == RIGHT)
		e->roty -= (5 * (M_PI / 90));
	loop_hook(e);
	return (0);
}

void		ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->bpp = 4;
	e->endian = 1;
	e->s_line = WIDTH;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->rot += 90;
	e->roty -= 90;
	e->zh -= 3;
	e->color = mlx_get_color_value(e->mlx, 0xFEFEFE);
	e->color3 = mlx_get_color_value(e->mlx, 0x8F732);
	e->color2 = mlx_get_color_value(e->mlx, 0xFF0921);
	mlx_hook(e->win, 2, 2, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
