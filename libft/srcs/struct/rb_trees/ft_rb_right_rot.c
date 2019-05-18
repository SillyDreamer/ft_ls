/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_right_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:12:22 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:27:06 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_right_rot(t_map *map, t_rb_node *x)
{
	t_rb_node	*y;

	y = x->left;
	x->left = y->right;
	if (y->right != map->nil)
		y->right->parent = x;
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
	y->right = x;
	x->parent = y;
}
