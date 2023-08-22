/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:18:55 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:18:56 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	xxx(unsigned int a, char b)
// {
// 	if (b < 'n' && a) {
// 		return ('A');
// 	}
// 	else
// 		return ('E');
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("Haben", xxx));
// }