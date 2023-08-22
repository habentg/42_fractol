/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:14:46 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:14:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int alpha)
{
	if ((alpha >= 32 && alpha <= 126))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isprint(31));
// }
