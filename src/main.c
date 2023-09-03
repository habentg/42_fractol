/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:12:41 by fkidane           #+#    #+#             */
/*   Updated: 2023/09/03 18:15:12 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(int argc, char **argv, t_fractal **data)
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
		(*data)->c_re = ft_atof(argv[2], (*data));
		(*data)->c_im = ft_atof(argv[3], (*data));
		julia_set(data);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	*data;

	data = (t_fractal *)malloc(sizeof(t_fractal));
	if (!data)
		ft_error("ERROR! Memory allocation failed!", data);
	handle_error(argc, argv, data);
	init_fractal(argc, argv, &data);
	free(data);
	return (0);
}
