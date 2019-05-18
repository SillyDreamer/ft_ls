/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_del_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:08:55 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/13 06:25:24 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

static void	ft_case_one(t_map *map, t_rb_node *y, t_rb_node *x, t_rb_node *z)
{
	x->parent = y->parent;
	if (y->parent && y->parent != map->nil)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
		map->root = x;
	if (y != z)
	{
		z->key = y->key;
		if (z->data != map->nil)
			free(z->data);
		z->data = y->data;
	}
	else if (y->data != map->nil)
	{
		free(y->data);
		y->data = NULL;
	}
}

void		ft_rb_del_node(t_map *map, int key)
{
	t_rb_node	*x;
	t_rb_node	*y;
	t_rb_node	*z;

	z = ft_rb_find_node(map, key);
	if (!z || z == map->nil)
		return ;
	if ((z->right == map->nil) || (z->left == map->nil))
		y = z;
	else
	{
		y = z->left;
		while (y->right != map->nil)
			y = y->right;
	}
	x = ((y->left != map->nil) ? y->left : y->right);
	ft_case_one(map, y, x, z);
	if (y->color == RB_BLACK)
		ft_rb_del_fix(map, x);
	free(y);
	map->size -= 1;
}
