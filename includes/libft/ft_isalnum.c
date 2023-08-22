/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:14:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:14:12 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z')
		|| (alpha >= '0' && alpha <= '9'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isalnum(' '));
// 	printf("%d", ft_isalnum('W'));
// }
