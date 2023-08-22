/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2023/08/23 03:15:11 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 900

/*key codes*/
# define ESC_KEY 53
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DEFAULT 2
# define ITERATE 34
# define ZOOM_IN 4
# define ZOOM_OUT 5

/*our graphics env*/
typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_mlx;

/*our dear fractal*/
typedef struct s_fractal
{
	t_mlx			mlx;
	int				x;
	int				y;
	double			c_re;
	double			c_im;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			zoom;
	double			mv_x;
	double			mv_y;
	int				max_iter;
	int				fract_id;
	int				color;
}					t_fractal;

/* fractal funcs*/
void	init_fractal(int argc, char **argv, t_fractal **data);
void	mandel_init(t_fractal **mandel);
void	mandel_draw(t_fractal **mandel);
void	mandel(t_fractal **mandel);
void	fract_calculate(t_fractal **mandel, int *i);
void	julia_set(t_fractal **julia);
void	julia_draw(t_fractal **julia);
void	julia_init(t_fractal **julia);

/*key hooks*/
int		close_func(t_fractal *fractal);
int		key_events_handler(int key_code, t_fractal *fract);

/*mouse hooks*/
int		mouse_event_handler(int mouse_code, int x, int y, t_fractal *fract);

/*Error handling funcs*/
void	handle_error(int argc, char **argv);

/* helper funcs*/
double	ft_atof(char *str);
#endif
