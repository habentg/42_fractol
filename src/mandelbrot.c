/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:12:36 by fkidane           #+#    #+#             */
/*   Updated: 2023/08/23 05:21:42 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandel_init(t_fractal **mandel)
{
	t_fractal	*m;

	m = *mandel;
	m->mlx.mlx_ptr = mlx_init();
	m->mlx.img = mlx_new_image(m->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (m->fract_id == 1)
		m->mlx.mlx_win = mlx_new_window(m->mlx.mlx_ptr, \
			WIDTH, HEIGHT, "MandelBrot Fractal");
	else
		m->mlx.mlx_win = mlx_new_window(m->mlx.mlx_ptr, \
			WIDTH, HEIGHT, "Burningship Fractal");
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp), \
		&(m->mlx.line_len), &(m->mlx.endian));
	m->c_re = 0;
	m->c_im = 0;
	m->new_re = 0.0;
	m->new_im = 0.0;
	m->zoom = 0.85;
	m->mv_x = 0.3;
	m->mv_y = 0;
	m->max_iter = 100;
	m->color = 0x00ccf1ff;
}

void	mandel_draw(t_fractal **mandel)
{
	int			i;
	t_fractal	*m;

	m = *mandel;
	m->y = -1;
	while (++(m->y) < HEIGHT)
	{
		m->x = -1;
		while (++(m->x) < WIDTH)
		{
			m->c_re = 1.5 * (m->x - WIDTH / 2)
				/ (m->zoom * WIDTH / 2) - m->mv_x;
			m->c_im = (m->y - HEIGHT / 2)
				/ (m->zoom * HEIGHT / 2) - m->mv_y;
			m->new_re = 0;
			m->new_im = 0;
			fract_calculate(&m, &i);
			if (i == m->max_iter)
				m->mlx.addr[m->y * WIDTH + m->x] = 0;
			else
				m->mlx.addr[m->y * WIDTH + m->x] = (i >> 1) * m->color;
		}
	}
}

void	mandel(t_fractal **mandel)
{
	mandel_init(mandel);
	mandel_draw(mandel);
	mlx_put_image_to_window((*mandel)->mlx.mlx_ptr, \
		(*mandel)->mlx.mlx_win, (*mandel)->mlx.img, 0, 0);
	mlx_hook((*mandel)->mlx.mlx_win, 17, 1L << 17, close_func, (*mandel));
	mlx_key_hook((*mandel)->mlx.mlx_win, key_events_handler, (*mandel));
	mlx_mouse_hook((*mandel)->mlx.mlx_win, mouse_event_handler, (*mandel));
	mlx_loop((*mandel)->mlx.mlx_ptr);
}
