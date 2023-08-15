/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkidane <finanmeharenak@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2023/08/15 13:41:46 by fkidane          ###   ########.fr       */
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

typedef struct s_mlx
{
	void			*mlx_ptr; // pointer to (initialized) mlx instance
	void			*mlx_win; // pointer to the width X height window
	void			*img; // pointer to the frame we are ploting each pixel into
	int				*addr; // address of each byte ( + offset), we will manuplate this to change colors
	int				bpp; //pits per pixel--- usually 
	int				line_len;
	int				endian;
}					t_mlx;

typedef struct s_fractal
{
	t_mlx			mlx;
	int				x;
	int				y;
	double			c_re;
	double			c_im;
	double			n_re;
	double			n_im;
	double			o_re;
	double			o_im;
	double			zoom;
	double			m_x;
	double			m_y;
	int				max_iter;
	int				flag;
	int				color;
}					t_fractal;

void    init_fractal(int argc, char **argv, t_fractal *data);
void    mandel_init(t_fractal *m);
void	ft_mandel(t_fractal *mandel);
#endif
