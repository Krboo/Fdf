/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:46:24 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/11 20:00:42 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		loop_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	e->rot += (2 * M_PI / WIDTH);
	draw(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

void	key_hook2(int keycode, t_env *e)
{
	if (keycode == LEFT)
	{
		e->rot += (3 * M_PI / 90);
	}
	if (keycode == RIGHT)
	{
		e->rot -= (3 * M_PI / 90);
	}
	if (keycode == UP)
	{
		e->roty += (3 * M_PI / 90);
	}
	if (keycode == DOWN)
	{
		e->roty -= (3 * M_PI / 90);
	}
}

int		mouse_hook(int button, int x, int y, t_env *c)
{
	if (button == 1)
	{
		c->zoom += 1;
		c->off = x;
		c->off2 = y;
	}
	if (button == 2)
	{
		c->off = x;
		c->off2 = y;
		c->zoom -= (c->zoom > 0 ? 1 : 0);
	}
	mlx_destroy_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->data = mlx_get_data_addr(c->img, &(c->bpp), &(c->s_line), &(c->endian));
	expose_hook(c);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == Z_MINE)
		e->zh += 3;
	if (keycode == Z_PLUS)
		e->zh -= 3;
	if (keycode == ZOOM)
		e->zoom += 3;
	if (keycode == DEZOOM)
		e->zoom -= 3;
	key_hook2(keycode, e);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	expose_hook(e);
	return (0);
}

void	ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->bpp = 4;
	e->endian = 1;
	e->s_line = WIDTH;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->zh -= 3;
	e->color = mlx_get_color_value(e->mlx, 0x0099bb);
	e->color2 = mlx_get_color_value(e->mlx, 0x66001b);
	e->color3 = mlx_get_color_value(e->mlx, 0x00561b);
	mlx_hook(e->win, 2, 1L << 2, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
