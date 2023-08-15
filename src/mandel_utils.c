/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:03:40 by aandom            #+#    #+#             */
/*   Updated: 2023/08/15 20:15:09 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void mandel_calculate(t_fractal *f, int *i)
{
    *i = -1;  // Initialize the iteration counter to -1
    // Iterate until the maximum number of iterations (f->max_iter) is reached
    while (++(*i) < f->max_iter)
    {
        // Save the current real and imaginary values to the old real and old imaginary variables
        f->old_re = f->new_re;
        f->old_im = f->new_im;
        
        // Update the new real and imaginary values using the Mandelbrot formula
        f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
        
        // Depending on the value of f->flag, calculate the new imaginary value
        // if (f->flag == 1)
        //     f->n_im = 2 * fabs(f->o_re * f->o_im) + f->c_im;
        // else
        f->new_im = 2 * (f->old_re * f->old_im) + f->c_im;
    
        // Check if the squared magnitude of the new complex number exceeds 4
        // If it does, the iteration is terminated
        if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
        {
            break ;
        }
    }
}