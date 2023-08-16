/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:39:27 by aandom            #+#    #+#             */
/*   Updated: 2023/08/17 00:38:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_func(t_fractal **fractal)
{
	if ((*fractal)->mlx.mlx_ptr || (*fractal)->mlx.img)
		mlx_destroy_image((*fractal)->mlx.mlx_ptr, (*fractal)->mlx.img);
	if ((*fractal)->mlx.mlx_ptr || (*fractal)->mlx.mlx_win)
		mlx_destroy_window((*fractal)->mlx.mlx_ptr, (*fractal)->mlx.mlx_win);
	exit(0);
}

void    back_default(t_fractal **fract)
{
    (*fract)->mv_x = 0.0;
    (*fract)->mv_y = 0.0;
    (*fract)->zoom = 1;
    (*fract)->color = 0x38004a;
    
}

void	iterate_more(t_fractal **fract)
{
	if ((*fract)->max_iter < 200)
		(*fract)->max_iter += 10;
	else if ((*fract)->max_iter >= 200)
		(*fract)->max_iter = 50;
}

int key_events_handler(int key_code, t_fractal *fract)
{
    mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.mlx_win);
    if (key_code == ESC_key)
        close_func(&fract);
    else if(key_code == UP_ARROW || key_code == DOWN_ARROW || key_code == RIGHT_ARROW || key_code == LEFT_ARROW)
    {
        if (key_code == DOWN_ARROW)
            fract->mv_y = fract->mv_y + 0.5 / fract->zoom;
        else if (key_code == UP_ARROW)
            fract->mv_y = fract->mv_y - 0.5 / fract->zoom;
        else if (key_code == RIGHT_ARROW)
            fract->mv_x = fract->mv_x + 0.5 / fract->zoom;
        else if (key_code == LEFT_ARROW)
            fract->mv_x = fract->mv_x - 0.5 / fract->zoom;
    }
    else if (key_code == DEFAULT)
        back_default(&fract);
    else if (key_code == ITERATE)
        iterate_more(&fract);
    if (fract->fract_id == 2 || fract->fract_id == 1)
		mandel_draw(&fract);
    mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.mlx_win, fract->mlx.img, 0, 0);
    return (0);
}