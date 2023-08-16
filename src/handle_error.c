/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:14:35 by aandom            #+#    #+#             */
/*   Updated: 2023/08/17 01:23:44 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void    display_error(int err_code)
{
    if (err_code == 0)
        ft_putendl_fd("\nERROR!!\nAvailable fractals:\n\n  m - Mandelbrot\n  b - Burning ship\n  j - Julia Set\n", 1);
    else if (err_code == 1)
        ft_putendl_fd("\nERROR!!\nAvailable fractals:\n\n  m - Mandelbrot\n  b - Burning ship\n  j - Julia Set\n\nUsage format:\n  ./fractal [m/b] - for mandelbror or burning ship\n  ./fractal j R I - for Julia set add the real and imaginary coordinates.", 1);
    
}

void    handle_error(int argc, char **argv)
{
    if (argc >= 2 && argc <= 4)
        if (ft_strncmp(argv[1], "m", 2) && ft_strncmp(argv[1], "b", 2) && ft_strncmp(argv[1], "j", 2))
            display_error(0);
    if (argc < 2)
        display_error(1);
    else if (argc > 2 && (!ft_strncmp(argv[1], "m", 2) || !ft_strncmp(argv[1], "b", 2)))
        ft_putendl_fd("\nERROR!!\nThis fractal doesnt accept other options!", 1);
    else if (!(argc == 4) && (!ft_strncmp(argv[1], "j", 2)))
        ft_putendl_fd("\nERROR!!\nJulia Set needs [only] two parameters!", 1);
}