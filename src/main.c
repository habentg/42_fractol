/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:48:39 by aandom            #+#    #+#             */
/*   Updated: 2023/08/14 16:56:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    fract_init(t_fractol *data)
{
    if (data->fract == 0)
		printf("julia");//mandelbrot_init(data);
	else if (data->fract == 1)
		printf("julia");//julia_init(data);
	else if (data->fract == 2)
		printf("ship");//burningship_init(data);
}

void    my_fracts(char **argv, t_fractol *data)
{
    if (ft_strncmp(argv[1], "mandel", 7) == 0)
		data->fract = 0;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
		data->fract = 1;
	else if (ft_strncmp(argv[1], "ship", 12) == 0)
		data->fract = 2;
	else
		ft_putendl_fd("\nInvalid parameter!!\n\nAvailable options: mandel, julia xR yI, ship", 1);
}

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int main(int argc, char **argv)
{
    t_fractol   *data;
    
    data = (t_fractol *)malloc(sizeof(t_fractol));
    if (!data)
        return (-1);
    if (argc ==4 || argc ==2)
    {
        mlx_win_init(data);
		my_fracts(argv, data);
		fract_init(data);
		mlx_loop(data->mlx);
    }
    else
        ft_putendl_fd("ERROR, invalid number of parameter!!", 1);
    return(0);
}