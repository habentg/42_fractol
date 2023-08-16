/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:25:17 by aandom            #+#    #+#             */
/*   Updated: 2023/08/16 22:41:30 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mouse_event_handler(int mouse_code, int x, int y, t_fractal   *fract)
{
    printf("%d \n", mouse_code);
    mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.mlx_win);
    if (mouse_code == 4)
	{
		fract->mv_x += 0.00113 * ((WIDTH / 2) - x) / fract->zoom;
		fract->mv_y += 0.00113 * ((HEIGHT / 2) - y) / fract->zoom;
		fract->zoom *= 1.5;
	}
	else if (mouse_code == 5)
	{
		if (fract->zoom > 0.5)
			fract->zoom /= 1.5;
	}
    if (fract->fract_id == 2 || fract->fract_id == 1)
		mandel_draw(&fract);
    mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.mlx_win, fract->mlx.img, 0, 0);
    return (0);
}