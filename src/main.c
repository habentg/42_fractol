/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkidane <finanmeharenak@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:12:41 by fkidane           #+#    #+#             */
/*   Updated: 2023/08/15 13:11:27 by fkidane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/* initialize our set based on thier choice */
void    init_fractal(int argc, char **argv, t_fractal *data)
{
    if (argc == 2 && ft_strncmp(argv[1], "mandel", 7))
         mandel(data);
    else if (argc == 2 && ft_strncmp(argv[1], "ship", 5))
        printf("s"); //ship(data);
    else if (argc == 4 && ft_strncmp(argv[1], "julia", 6))
        printf("j"); //julia(data, argv);
    else
        ft_putendl_fd("Error, Wrong para!", 1);
}

int main(int argc, char ** argv)
{
    t_fractal   *data; // pointer to out respective set
    
    // handle any input error here

    // calculate and desplay our sets ---- real deal lmao 
    init_fractal(argc, argv, data);
    return (0);
}