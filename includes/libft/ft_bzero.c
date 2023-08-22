/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:13:48 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:13:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	ft_memset(dest, 0, n);
}

// int	main(void)
// {
// 	char buf[10];
// 	ft_bzero(buf, 10);
// 	for (int x = 0; x < 10; x++)
// 	{
// 		printf("%d ", buf[x]);
// 	}
// 	printf("%s\n", "done");
// }
