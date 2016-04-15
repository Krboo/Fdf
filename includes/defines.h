/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:19:33 by pmartine          #+#    #+#             */
/*   Updated: 2016/04/15 18:19:38 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINES_H
# define FDF_DEFINES_H

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM 69
# define DEZOOM 78
# define Z_MINE 6
# define Z_PLUS 7
# define ECHAP 53

# define WIDTH 1500
# define HEIGHT 750
# define XCENTER (WIDTH / 2)   
# define YCENTER (HEIGHT / 2)
# define OFF 1.00
# define YOFF 1.00
# define CT1 0.5
# define CT2 0.5

# define XR1(x) (x*(cos(e->roty)))
# define XR2(x) (x*(cos((e->roty) + M_PI/2)))
# define YR1(y) (y*(sin(e->roty))*(sin(e->rot)))
# define YR2(y) (y*(sin((e->roty) + M_PI/2))*(sin(e->rot)))
# define XA CT1*XR1(e->inc->x1) + CT2*XR2(e->inc->y1)
# define YA -((e->inc->z) * sin((e->rot) + M_PI/2)) + (CT1/2*YR1(e->inc->x1)) + CT2/2*YR2(e->inc->y1)
# define XB CT1*XR1(e->inc->x2) + CT2*XR2(e->inc->y1)
# define YB -((e->inc->z2) * sin((e->rot) + M_PI/2)) + CT1/2*YR1(e->inc->x2) + CT2/2*YR2(e->inc->y1)
# define XC CT1*XR1(e->inc->x1) + CT2*XR2(e->inc->y2)
# define YC -((e->inc->z3) * sin((e->rot) + M_PI/2)) + CT1/2*YR1(e->inc->x1) + CT2/2*YR2(e->inc->y2)

#endif
