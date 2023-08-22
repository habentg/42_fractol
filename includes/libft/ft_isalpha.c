/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:14:21 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:14:21 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_isalpha(' '));
// 	printf("%d", ft_isalpha('W'));
// }
