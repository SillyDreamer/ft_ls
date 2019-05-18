/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 08:59:13 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:35:38 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lst_ft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	while (*alst != NULL)
	{
		tmp = (*alst);
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}
