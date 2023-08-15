/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkidane <finanmeharenak@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2023/08/15 17:04:37 by fkidane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# define WIDTH 800 // window width
# define HEIGHT 600 // window height

typedef struct s_mlx
{
	void			*mlx_ptr; // pointer to (initialized) mlx instance
	void			*mlx_win; // pointer to the width X height window
	void			*img; // pointer to the frame we are ploting each pixel into
	int				*addr; // address of each byte ( + offset), we will manuplate this to change colors
	int				bpp; //pits per pixel, for color depth--- usually 8 bps represents 256 shades of color
	int				line_len; // The number of bytes used to store a single line of the image.
	int				endian; // order used to store info, eg: 5f a4 little indian(a4 5f) big indian(5f a4) 
}					t_mlx;

typedef struct s_fractal
{
	t_mlx			mlx; // instance of the mlx graphics env
	int				x; // horizontal coordinate of the 2D window
	int				y; // vertical
	double			c_re; // real part of c in the equition Zn+1 = Zn**2 + C; where C = re + im
	double			c_im; // imaginary
	double			z_re; // real part of c in the equition Zn+1 = Zn**2 + C; After every calcu
	double			z_im; // imaginary
	double			o_re;
	double			o_im;
	double			zoom; // zoom level
	double			m_x;
	double			m_y;
	int				max_iter; // max iteration
	int				fract;
	int				color; // chosen color to represent the bit
}					t_fractal;

void    init_fractal(int argc, char **argv, t_fractal *data);
void    mandel_init(t_fractal *m);
void	mandel(t_fractal *mandel);
#endif
