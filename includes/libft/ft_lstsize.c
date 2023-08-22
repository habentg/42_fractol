/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:37 by hatesfam          #+#    #+#             */
/*   Updated: 2023/01/16 22:16:10 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp_node;

	i = 0;
	temp_node = lst;
	while (temp_node != NULL)
	{
		temp_node = temp_node->next;
		i++;
	}
	return (i);
}
