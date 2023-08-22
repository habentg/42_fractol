/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:09:09 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/18 12:32:33 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	count;
	size_t	x;
	char	*temp;

	if (!s)
		return ;
	temp = (char *)s;
	count = 0;
	x = ft_strlen(s);
	while (count < x)
	{
		f(count, &temp[count]);
		count++;
	}
}
