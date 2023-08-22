/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:14:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:14:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int alpha)
{
	if ((alpha >= 0 && alpha < 128))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isascii('1'));
// }
