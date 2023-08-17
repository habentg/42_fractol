/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:27:21 by aandom            #+#    #+#             */
/*   Updated: 2023/08/17 13:52:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"


int before_deci_f(char *str)
{
    int i;
    int before_dot;

    i = -1;
    before_dot = 0;
    if(str[0] == '-')
        ++i;
    while (str[++i] && str[i] != '.')
    {
        if (!ft_isdigit(str[i]))
            ft_putendl_fd("Invalid parameter for julia set\n", 1);
        before_dot = before_dot * 10 + (str[i] - '0');
    }
    return (before_dot);
}

double  ft_atof(char *str)
{
    double before_deci;
    double after_deci;
    double res;
    int i;
    double factor;
    int sign;

    i = 0;
    before_deci = (double)before_deci_f(str);
    after_deci = 0;
    factor = 0.1;
    sign = 1;
    if(str[0] == '-')
    {
        ++i;
        sign = -1;
    }
    while (str[i] != '\0' && str[i] != '.')
        i++;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            ft_putendl_fd("Invalid parameter for julia set\n", 1);
        after_deci += (str[i] - '0') * factor;
        factor *= 0.1;
    }
    // printf("before decimal: %f\n", before_deci);
    // printf("after decimal: %f\n", after_deci);
    res = (before_deci + after_deci) * sign;
    // printf("\n =====all : %f\n", res);
    return (res);    
}

// int main (int argc, char **argv)
// {
//     if (argc == 2)
//         ft_atof(argv[1]);
// }
