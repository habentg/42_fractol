/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:02 by aandom            #+#    #+#             */
/*   Updated: 2023/09/03 16:26:06 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_calculate(t_fractal **fract, int *i)
{
	t_fractal	*f;

	f = *fract;
	*i = -1;
	while (++(*i) < f->max_iter)
	{
		f->old_re = f->new_re;
		f->old_im = f->new_im;
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
		if (f->fract_id == 2)
			f->new_im = 2 * fabs(f->old_re * f->old_im) + f->c_im;
		else
			f->new_im = 2 * (f->old_re * f->old_im) + f->c_im;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 4)
			break ;
	}
}
