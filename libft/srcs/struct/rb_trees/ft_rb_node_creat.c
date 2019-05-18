/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_node_creat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:01:43 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/13 06:55:21 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_rb_node	*ft_rb_node_creat(t_map *map, int key)
{
	t_rb_node	*new;

	if (!(new = (t_rb_node *)malloc(sizeof(t_rb_node))))
		return (NULL);
	new->color = RB_RED;
	new->left = map->nil;
	new->right = map->nil;
	new->parent = map->nil;
	new->key = key;
	new->data = map->nil;
	map->size += 1;
	return (new);
}
