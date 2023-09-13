/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:14:14 by fseles            #+#    #+#             */
/*   Updated: 2023/09/13 19:14:19 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*element;
	t_list	*element_to_delete;

	if (lst != NULL)
	{
		if (*lst)
		{
			element_to_delete = *lst;
			element = *lst;
			while (element->next != NULL)
			{
				element_to_delete = element;
				element = element->next;
				del(element_to_delete);
				free(element_to_delete);
			}
			del(element);
			free(element);
		}
		lst = NULL;
	}
}