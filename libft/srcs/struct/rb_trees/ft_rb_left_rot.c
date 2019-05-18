/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_left_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:11:34 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:26:04 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_left_rot(t_map *map, t_rb_node *x)
{
	t_rb_node	*y;

	y = x->right;
	x->right = y->left;
	if (y->left != map->nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == map->nil)
		map->root = y;
	else
	{
		if (x == (x->parent)->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
