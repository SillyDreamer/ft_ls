/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:54:49 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:36:29 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lst_ft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	if (!lst || !f)
		return (NULL);
	fresh = f(lst);
	if (fresh)
	{
		fresh->next = ft_lstmap(lst->next, f);
		if (fresh->next == NULL && lst->next != NULL)
		{
			free(fresh->content);
			fresh->content = NULL;
			free(fresh);
			return (NULL);
		}
	}
	return (fresh);
}
