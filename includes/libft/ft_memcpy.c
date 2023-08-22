/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:16:31 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:16:31 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
//     char    dest[256] = "xxxx";
//     const char src[256] = "hello world";

//     ft_memcpy(dest, src, 3);
//     for (int i = 0; i < 15; i++)
//     {
//         printf("%c", dest[i]);
//     }
// }
