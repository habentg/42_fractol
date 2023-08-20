/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:14:35 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 14:58:50 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	display_error(int err_code)
{
	if (err_code == 0)
	{
		ft_putendl_fd("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n", 1);
		exit(0);
	}
	else if (err_code == 1)
	{
		ft_putendl_fd("\nERROR!!\nAvailable fractals:\n\n  m - \
			Mandelbrot\n  b - Burning ship\n  j - Julia Set\n\nUsage format:\n  \
				./fractal [m/b] - for mandelbror or burning ship\n  ./fractal j R I - for Julia set add the \
					real and imaginary coordinates.", 1);
		exit(0);
	}
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
	{
		ft_putendl_fd("\nERROR!!\nThis fractal doesnt accept other options!", 1);
		exit(0);
	}
	else if (!(argc == 4) && (!ft_strncmp(argv[1], "j", 2)))
	{
		ft_putendl_fd("\nERROR!!\nJulia Set needs [only] two parameters! Use:\n  \
			./fractol j <real> <im>\n", 1);
		exit(0);
	}
}
