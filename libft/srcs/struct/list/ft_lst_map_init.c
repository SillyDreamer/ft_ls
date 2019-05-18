/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:47:15 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/01/07 10:53:23 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lst_ft.h"

t_listmap	*ft_lst_map_init(t_list *list)
{
	t_listmap *map;

	if (!(map = (t_listmap *)malloc(sizeof(t_listmap))))
		return (NULL);
	map->begin = list;
	map->size = 0;
	return (map);
}
