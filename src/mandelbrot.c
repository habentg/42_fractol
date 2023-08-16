/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:12:36 by fkidane           #+#    #+#             */
/*   Updated: 2023/08/17 00:08:17 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandel_init(t_fractal **mandel)
{ /* we can use for burning ship as well --- keep it in mind*/
	t_fractal	*m;
	
	m = *mandel;
    m->mlx.mlx_ptr = mlx_init(); // initialize the mlx library, connecting it with the graphic system of macOS
    
	m->mlx.mlx_win = mlx_new_window(m->mlx.mlx_ptr, WIDTH, HEIGHT, "MandelBrot Fractal"); // create a new window
	m->mlx.img = mlx_new_image(m->mlx.mlx_ptr, WIDTH, HEIGHT); // create a new image where we will plot our shit
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp), &(m->mlx.line_len), &(m->mlx.endian)); // address of our image
		
	m->c_re = 0; // real part of c in the equition Zn+1 = Zn**2 + C; where C = re + im
	m->c_im = 0; // imaginary part of the above
	m->new_re = 0.0; // real num - after computing the aabove quadratic func
	m->new_im = 0.0; // im num
	m->zoom = 1.0; // zoom level
	m->mv_x = 0;
	m->mv_y = 0;
	m->max_iter = 42; // max number of iteration in each pixel to determine whether its result diverge or converge
	m->color = 0x38004a; // gonna be our default color
}

void mandel_calculate(t_fractal **mandel, int *i)
{
	t_fractal	*m;
	
	m = *mandel;
    *i = -1;  // Initialize the iteration counter to -1
    // Iterate until the maximum number of iterations (f->max_iter) is reached
    while (++(*i) < m->max_iter)
    {
        // Save the current real and imaginary values to the old real and old imaginary variables
        m->old_re = m->new_re;
        m->old_im = m->new_im;
        // Update the new real and imaginary values using the Mandelbrot formula
        m->new_re = m->old_re * m->old_re - m->old_im * m->old_im + m->c_re;
        // Depending on the value of id calculate the new imaginary value
        if (m->fract_id == 1)
        	m->new_im = 2 * (m->old_re * m->old_im) + m->c_im;
        else
            m->new_im = 2 * fabs(m->old_re * m->old_im) + m->c_im;
        // Check if the squared magnitude of the new complex number exceeds 4
        // If it does, the iteration is terminated
        if ((m->new_re * m->new_re + m->new_im * m->new_im) > 4)
            break ;
    }
}

void mandel_draw(t_fractal **mandel)
{
    int i;
	t_fractal	*m;
	
	m = *mandel;
    m->y = -1; // x and y are the coordinate (x,y) from top left of the window
    while (++(m->y) < HEIGHT)
    {
        m->x = -1;
        while (++(m->x) < WIDTH)
        {
			m->c_re = 1.5 * (m->x - WIDTH / 2) / (m->zoom * WIDTH / 2) - m->mv_x;
			m->c_im = (m->y - HEIGHT / 2) / (m->zoom * HEIGHT / 2) - m->mv_y;
			m->new_re = 0;
			m->new_im = 0;
			mandel_calculate(&m, &i);
			if (i == m->max_iter)
				m->mlx.addr[m->y * WIDTH + m->x] = 0;
			else
				m->mlx.addr[m->y * WIDTH+ m->x] = (i >> 2) * m->color;
 		}   
    }
}

void	mandel(t_fractal **mandel)
{
	mandel_init(mandel); // initialize the default values of our mandel set
	mandel_draw(mandel); // put every pixel into the image because puting it directly is slow af
	mlx_put_image_to_window((*mandel)->mlx.mlx_ptr, (*mandel)->mlx.mlx_win, (*mandel)->mlx.img, 0, 0); // put image into window
	mlx_hook((*mandel)->mlx.mlx_win, 17, 1L << 17, close_func, (*mandel)); // close window using x at the top-right corner
	mlx_key_hook((*mandel)->mlx.mlx_win, key_events_handler, (*mandel));
	mlx_mouse_hook((*mandel)->mlx.mlx_win, mouse_event_handler, (*mandel));
	mlx_loop((*mandel)->mlx.mlx_ptr);
}
