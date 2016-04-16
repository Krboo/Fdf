/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:53:05 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/16 19:32:27 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "defines.h"

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

void				str_exit(char *str);
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
void				mlx_color(t_env *e, int x, int y);
void				ft_mlx(t_env *e);
void				draw(t_env *e);
t_coord				***ft_get_coord(t_map *map);
void				display(t_env *e);
void				free_all(t_env *e, t_map *map);
int					expose_hook(t_env *e);
#endif
