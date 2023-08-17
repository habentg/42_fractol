/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:09:05 by aandom            #+#    #+#             */
/*   Updated: 2023/08/17 15:00:05 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    julia_init(t_fractal **julia)
{
    t_fractal	*j;
	
	j = *julia;
    j->mlx.mlx_ptr = mlx_init(); // initialize the mlx library, connecting it with the graphic system of macOS
    j->mlx.mlx_win = mlx_new_window(j->mlx.mlx_ptr, WIDTH, HEIGHT, "Julia Fractal"); // create a new window
	j->mlx.img = mlx_new_image(j->mlx.mlx_ptr, WIDTH, HEIGHT); // create a new image where we will plot our shit
	j->mlx.addr = (int *)mlx_get_data_addr(j->mlx.img, &(j->mlx.bpp), &(j->mlx.line_len), &(j->mlx.endian)); // address of our image
	j->new_re = 0.0; // real num - after computing the aabove quadratic func
	j->new_im = 0.0; // im num
	j->zoom = 1.0; // zoom level
	j->mv_x = 0;
	j->mv_y = 0;
	j->max_iter = 60; // max number of iteration in each pixel to determine whether its result diverge or converge
	j->color = 0x38004a; // gonna be our default color
}

void    julia_draw(t_fractal **julia)
{
    int		i;
    t_fractal	*j;
	
	j = *julia;

	j->y = -1;
	while (++(j->y) < HEIGHT)
	{
		j->x = -1;
		while (++(j->x) < WIDTH)
		{
			j->new_re = -1.5 * (j->x - WIDTH / 2) / \
				(j->zoom * WIDTH / 2) - j->mv_x;
			j->new_im = (j->y - HEIGHT / 2) / \
				(j->zoom * HEIGHT / 2) - j->mv_y;
			fract_calculate(&j, &i);
			if (i == j->max_iter)
				j->mlx.addr[j->y * WIDTH + j->x] = 0;
			else
				j->mlx.addr[j->y * WIDTH + j->x] = j->color * (i >> 2);
		}
    }
}

void    julia_set(t_fractal **julia)
{
    julia_init(julia);
    julia_draw(julia);
    mlx_put_image_to_window((*julia)->mlx.mlx_ptr, (*julia)->mlx.mlx_win, (*julia)->mlx.img, 0, 0); // put image into window
	mlx_hook((*julia)->mlx.mlx_win, 17, 1L << 17, close_func, (*julia)); // close window using x at the top-right corner
	mlx_key_hook((*julia)->mlx.mlx_win, key_events_handler, (*julia));
	mlx_mouse_hook((*julia)->mlx.mlx_win, mouse_event_handler, (*julia));
	mlx_loop((*julia)->mlx.mlx_ptr);
}