/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:54:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:17:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (str)
	{
		ft_putstr_fd(str, fd);
		write(fd, "\n", 1);
	}
}

// int	main(void)
// {
//     ft_putendl_fd("haben", 1);
// }