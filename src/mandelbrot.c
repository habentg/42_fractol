/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:12:36 by fkidane           #+#    #+#             */
/*   Updated: 2023/08/15 19:53:31 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandel_init(t_fractal *m)
{ /* we can use for burning ship as well --- keep it in mind*/
    m->mlx.mlx_ptr = mlx_init(); // initialize the mlx library, connecting it with the graphic system of macOS
    
	m->mlx.mlx_win = mlx_new_window(m->mlx.mlx_ptr, WIDTH, HEIGHT, "MandelBrot Fractal");
	m->mlx.img = mlx_new_image(m->mlx.mlx_ptr, WIDTH, HEIGHT);
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp), &(m->mlx.line_len), &(m->mlx.endian));
		
	m->c_re = 0; // real part of c in the equition Zn+1 = Zn**2 + C; where C = re + im
	m->c_im = 0; // imaginary part of the above
	m->new_re = 0.0;
	m->new_im = 0.0;
	m->zoom = 1.0; // zoom level
	m->m_x = 0;
	m->m_y = 0;
	m->max_iter = 50; // max number of iteration in each pixel to determine whether its result diverge or converge
	m->color = 0x31f04a; // random ass color lmao
}

static void mandel_draw(t_fractal *m)
{
    int i;

    m->y = -1; // x and y are the coordinate (x,y) from top left of the window
    while (++(m->y) < HEIGHT)
    {
        m->x = -1;
        while (++(m->x) < WIDTH)
        {
			m->c_re = 1.5 * (m->x - WIDTH / 2) / (m->zoom * WIDTH / 2) - m->m_x;
			m->c_im = (m->y - HEIGHT / 2) / (m->zoom * HEIGHT / 2) - m->m_y;
			m->new_re = 0;
			m->new_im = 0;
			mandel_calculate(m, &i);
			if (i == m->max_iter)
				m->mlx.addr[m->y * WIDTH + m->x] = 0;
			else
				m->mlx.addr[m->y * WIDTH+ m->x] = (i >> 2) * m->color;
 		}
        
    }
    
}

void	mandel(t_fractal *mandel)
{
	printf("init mandel \n");
	mandel_init(mandel); // initialize the default values of our mandel set
	printf("draw mandel \n");
	mandel_draw(mandel); // put every pixel into the image because puting it directly is slow af
	printf("put shit on win \n");
	printf("put shit on win \n");
	printf("put shit on win \n");
	printf("put shit on win \n");
	printf("put shit on win \n");
	mlx_put_image_to_window(mandel->mlx.mlx_ptr, mandel->mlx.mlx_win, mandel->mlx.img, 0, 0); // put image into window
	printf("what to do0 o do lu");
	// mlx_hook(m->mlx.mlx_win, 17, 1L << 17, ft_exit, m); 
	// mlx_key_hook(m->mlx.mlx_win, ft_key_events_mandel, m);
	// mlx_mouse_hook(m->mlx.mlx_win, ft_mouse_events, m);
	mlx_loop(mandel->mlx.mlx_ptr);
}