/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:14:35 by aandom            #+#    #+#             */
/*   Updated: 2023/09/03 18:08:47 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(char *msg, t_fractal *fractal)
{
	ft_putendl_fd(msg, 1);
	free(fractal);
	exit (0);
}

static void	display_error(int err_code, t_fractal *fractal)
{
	if (err_code == 0)
		ft_error("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n", fractal);
	else if (err_code == 1)
		ft_error("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n\nUsage format:\n  \
				./fractal [m/b] - for mandelbror or burning ship\n  ./fractal j R I - for Julia set add the \
					real and imaginary coordinates.", fractal);
}

void	handle_error(int argc, char **argv, t_fractal *fractal)
{
	if (argc >= 2 && argc <= 4)
		if (ft_strncmp(argv[1], "m", 2) && ft_strncmp(argv[1], "b", 2) && \
			ft_strncmp(argv[1], "j", 2))
			display_error(0, fractal);
	if (argc < 2)
		display_error(1, fractal);
	else if (argc > 2 && (!ft_strncmp(argv[1], "m", 2) || \
		!ft_strncmp(argv[1], "b", 2)))
		ft_error("\nERROR!!\nThis fractal doesnt accept other options!", fractal);
	else if (!(argc == 4) && (!ft_strncmp(argv[1], "j", 2)))
		ft_error("\nERROR!!\nJulia Set needs [only] two parameters! Use:\n  \
			./fractol j <real> <im>\n", fractal);
}
