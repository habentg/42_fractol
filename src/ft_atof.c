/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:27:21 by aandom            #+#    #+#             */
/*   Updated: 2023/09/03 21:28:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	after_deci_f(char *str, t_fractal *fractal)
{
	double	after_deci;
	int		i;
	double	factor;

	i = 0;
	after_deci = 0;
	factor = 0.1;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Invalid parameter for julia set\n", fractal);
		after_deci += (str[i] - '0') * factor;
		factor *= 0.1;
	}
	return (after_deci);
}

static double	before_deci_f(char *str, t_fractal *fractal)
{
	int		i;
	double	before_dot;

	i = -1;
	before_dot = 0;
	if (str[0] == '-')
		++i;
	while (str[++i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			ft_error("Invalid parameter for julia set\n", fractal);
		before_dot = before_dot * 10 + (str[i] - '0');
	}
	return (before_dot);
}

double	ft_atof(char *str, t_fractal *fractal)
{
	double	before_deci;
	double	after_deci;
	double	res;
	int		sign;

	before_deci = before_deci_f(str, fractal);
	after_deci = after_deci_f(str, fractal);
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	res = (before_deci + after_deci) * sign;
	return (res);
}
