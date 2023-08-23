/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:14:35 by aandom            #+#    #+#             */
/*   Updated: 2023/08/23 04:24:37 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit (0);
}

static void	display_error(int err_code)
{
	if (err_code == 0)
		ft_error("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n");
	else if (err_code == 1)
		ft_error("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n\nUsage format:\n  \
				./fractal [m/b] - for mandelbror or burning ship\n  ./fractal j R I - for Julia set add the \
					real and imaginary coordinates.");
}

void	handle_error(int argc, char **argv)
{
	if (argc >= 2 && argc <= 4)
		if (ft_strncmp(argv[1], "m", 2) && ft_strncmp(argv[1], "b", 2) && \
			ft_strncmp(argv[1], "j", 2))
			display_error(0);
	if (argc < 2)
		display_error(1);
	else if (argc > 2 && (!ft_strncmp(argv[1], "m", 2) || \
		!ft_strncmp(argv[1], "b", 2)))
		ft_error("\nERROR!!\nThis fractal doesnt accept other options!");
	else if (!(argc == 4) && (!ft_strncmp(argv[1], "j", 2)))
		ft_error("\nERROR!!\nJulia Set needs [only] two parameters! Use:\n  \
			./fractol j <real> <im>\n");
}
