/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:53:05 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/11 20:02:37 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "defines.h"
# define INC e->zoom
# define SX2 e->coord[i + 1][0]->size_x
# define T e->rot
# define S e->roty
# define X1 e->inc->x1
# define Y1 e->inc->y1
# define X2 e->inc->x2
# define Y2 e->inc->y2
# define XR1(x) (x*(cos(T)))
# define XR2(x) (x*(cos(T+M_PI/2)))
# define YR1(y) (y*(sin(T))*(sin(S)))
# define YR2(y) (y*(sin(T+M_PI/2))*(sin(S)))
# define XA CT1*XR1(X1) + CT2*XR2(Y1)
# define YA -((e->inc->z) * sin(S+M_PI/2)) + (CT1/2*YR1(X1)) + CT2/2*YR2(Y1)
# define XB CT1*XR1(X2) + CT2*XR2(Y1)
# define YB -((e->inc->z2) * sin(S+M_PI/2)) + CT1/2*YR1(X2) + CT2/2*YR2(Y1)
# define XC CT1*XR1(X1) + CT2*XR2(Y2)
# define YC -((e->inc->z3) * sin(S+M_PI/2)) + CT1/2*YR1(X1) + CT2/2*YR2(Y2)

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;

typedef struct		s_coor_box
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	float			xc;
	float			yc;
	float			coeff;
}					t_box;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	unsigned char	r3;
	unsigned char	g3;
	unsigned char	b3;
}					t_color;

typedef struct		s_inc
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z;
	int				z2;
	int				z3;
	int				color;
	int				color2;
	int				color3;
}					t_inc;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned long	color;
	unsigned long	color2;
	unsigned long	color3;
	t_coord			***coord;
	t_inc			*inc;
	t_color			*colorpix;
	t_box			*box;
	int				off;
	int				off2;
	int				endian;
	int				zoom;
	int				max_x;
	int				max_y;
	int				zh;
	int				bpp;
	int				s_line;
	int				z;
	float			rot;
	float			roty;
	char			*data;
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	char			**tmp;
	int				y;
	int				x;
}					t_map;

void				crux_x(int x1, int y1, int x2, t_env *c);
void				crux_y(int x1, int y1, int y2, t_env *c);
void				crux(t_box *b, t_env *c);
void				octant_1(t_box *b, t_env *c);
void				octant_2(t_box *b, t_env *c);
void				octant_3(t_box *b, t_env *c);
void				octant_4(t_box *b, t_env *c);
void				octant_5(t_box *b, t_env *c);
void				octant_6(t_box *b, t_env *c);
void				octant_7(t_box *b, t_env *c);
void				octant_8(t_box *b, t_env *c);
void				vect_ab(t_box *b, t_env *c);
void				ring(t_env *c);
void				put_ring_arb(t_env *c);
void				vect(float x, float y, float x2, float y2, t_env *c);
void				ft_mlx(t_env *e);
void				draw(t_env *e);
void				mlx_color(t_env *e, int x, int y);
void				mlx_pxl(t_env *e, int x, int y, unsigned int place);
int					calc_dist_ab(float x, float y, float x2, float y2);
int					key_hook(int keycode, t_env *c);
int					mouse_hook(int button, int x, int y, t_env *c);
int					expose_base(t_env *c);
t_coord				***ft_get_coord(t_map *map);

#endif
