/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:31:55 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 00:12:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else
			i++;
	}
	return (0); //returning zero is success
}

// int main(void)
// {
// 	char str1[] = "abcdef";
// 	char str2[] = "abc\375xx";
// 	printf("strncmp returned\t%d\n", strncmp(str1, str2, 5));
// 	printf("ft_strncmp returned\t%d\n", ft_strncmp(str1, str2, 5));
// 	return (0);
// }
