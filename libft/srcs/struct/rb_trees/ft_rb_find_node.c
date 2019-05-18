/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_find_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:08:12 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/13 06:26:50 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

t_rb_node	*ft_rb_find_node(t_map *map, int key)
{
	t_rb_node	*c;

	c = map->root;
	while (c != map->nil)
	{
		if (key == c->key)
			return (c);
		if (key < c->key)
			c = c->left;
		else
			c = c->right;
	}
	return (map->nil);
}
