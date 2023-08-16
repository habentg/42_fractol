/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2023/08/17 00:34:29 by aandom           ###   ########.fr       */
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

/*key codes*/
# define ESC_key 53
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DEFAULT 2
# define ITERATE 34
# define ZOOM_IN 4
# define ZOOM_out 5
/*our graphics env*/
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

/*our dear fractal*/
typedef struct s_fractal
{
	t_mlx			mlx; // instance of the mlx graphics env
	int				x; // horizontal coordinate of the 2D window
	int				y; // vertical
	double			c_re; // real part of c in the equition Zn+1 = Zn**2 + C; where C = re + im
	double			c_im; // imaginary
	double			new_re; // real part of c in the equition Zn+1 = Zn**2 + C; After every calcu
	double			new_im; // imaginary
	double			old_re;
	double			old_im;
	double			zoom; // zoom level
	double			mv_x; // moving the x cordinate
	double			mv_y; // moving the x cordinate
	int				max_iter; // max iteration
	int				fract_id;
	int				color; // chosen color to represent the bit
}					t_fractal;

/* mandel funcs*/
void    init_fractal(int argc, char **argv, t_fractal **data);
void    mandel_init(t_fractal **mandel);
void	mandel_draw(t_fractal **mandel);
void	mandel(t_fractal **mandel);
void	mandel_calculate(t_fractal **mandel, int *i);

/*key hooks*/
int		close_func(t_fractal **fractal);
int		key_events_handler(int key_code, t_fractal *fract);
void    back_default(t_fractal **fract);

/*mouse hooks*/
int mouse_event_handler(int mouse_code, int x, int y, t_fractal   *fract);

/*Error handling funcs*/
void    handle_error(int argc, char **argv);
#endif
