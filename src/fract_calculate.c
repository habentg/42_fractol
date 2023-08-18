/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:02 by aandom            #+#    #+#             */
/*   Updated: 2023/08/17 19:25:10 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_calculate(t_fractal **fract, int *i)
{
	t_fractal	*f;

	f = *fract;
/*Initialize the iteration counter to -1*/
	*i = -1;
    // Iterate until the maximum number of iterations (f->max_iter) is reached
	while (++(*i) < f->max_iter)
	{
        // Save the current real and imaginary values to the old real and old imaginary variables
		f->old_re = f->new_re;
		f->old_im = f->new_im;
		// Update the new real and imaginary values using the Mandelbrot formula
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
		// Depending on the value of id calculate the new imaginary value
		if (f->fract_id == 2)
        	f->new_im = 2 * fabs(f->old_re * f->old_im) + f->c_im;
		else
			f->new_im = 2 * (f->old_re * f->old_im) + f->c_im;
        // Check if the squared magnitude of the new complex number exceeds 4
        // If it does, the iteration is terminated
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
			break ;
	}
}
