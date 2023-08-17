/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:12:41 by fkidane           #+#    #+#             */
/*   Updated: 2023/08/17 14:10:06 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/* initialize our set based on thier choice */
void    init_fractal(int argc, char **argv, t_fractal **data)
{
    if (argc == 2 && !ft_strncmp(argv[1], "m", 2))
    {
        (*data)->fract_id = 1;
        mandel(data);
    }
    else if (argc == 2 && !ft_strncmp(argv[1], "b", 2))
    {
        (*data)->fract_id = 2;
        mandel(data);
    }
    else if (argc == 4 && !ft_strncmp(argv[1], "j", 2))
    {
        (*data)->fract_id = 3;
        (*data)->c_re = ft_atof(argv[2]);
        (*data)->c_im = ft_atof(argv[3]);
        julia_set(data);
    }
}

int main(int argc, char ** argv)
{
    t_fractal   *data; // pointer to out respective set
    
    data = (t_fractal *)malloc(sizeof(t_fractal));
    if (!data)
        exit(0);
    // handle any input error here
    handle_error(argc, argv);
    // calculate and desplay our sets ---- real deal lmao 
    init_fractal(argc, argv, &data);
    free(data);
    return (0);
}