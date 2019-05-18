/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_del_fix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:05:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/11 19:34:42 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static void	del_ins_case1(t_map *map, t_rb_node **n, t_rb_node **x)
{
	if ((*n)->left->color == RB_BLACK && (*n)->right->color == RB_BLACK)
	{
		(*n)->color = RB_RED;
		(*x) = (*x)->parent;
	}
	else
	{
		if ((*n)->right->color == RB_BLACK)
		{
			(*n)->left->color = RB_BLACK;
			(*n)->color = RB_RED;
			ft_rb_right_rot(map, (*n));
			(*n) = (*x)->parent->right;
		}
		(*n)->color = (*x)->parent->color;
		(*x)->parent->color = RB_BLACK;
		(*n)->right->color = RB_BLACK;
		ft_rb_left_rot(map, (*x)->parent);
		(*x) = map->root;
	}
}

static void	del_ins_case2(t_map *map, t_rb_node **n, t_rb_node **x)
{
	if ((*n)->right->color == RB_BLACK && (*n)->left->color == RB_BLACK)
	{
		(*n)->color = RB_RED;
		(*x) = (*x)->parent;
	}
	else
	{
		if ((*n)->left->color == RB_BLACK)
		{
			(*n)->right->color = RB_BLACK;
			(*n)->color = RB_RED;
			ft_rb_left_rot(map, *n);
			*n = (*x)->parent->left;
		}
		(*n)->color = (*x)->parent->color;
		(*x)->parent->color = RB_BLACK;
		(*n)->left->color = RB_BLACK;
		ft_rb_right_rot(map, (*x)->parent);
		(*x) = map->root;
	}
}

static void	ft_color_change(t_rb_node **n, t_rb_node **x, t_map *map)
{
	if ((*n)->color == RB_RED)
	{
		(*n)->color = RB_BLACK;
		(*x)->parent->color = RB_RED;
		ft_rb_left_rot(map, (*x)->parent);
		(*n) = (*x)->parent->right;
	}
}

void		ft_rb_del_fix(t_map *map, t_rb_node *x)
{
	t_rb_node	*n;

	while (x != map->root && x->color == RB_BLACK)
	{
		if (x == x->parent->left)
		{
			n = x->parent->right;
			ft_color_change(&n, &x, map);
			del_ins_case1(map, &n, &x);
		}
		else
		{
			n = x->parent->left;
			if (n->color == RB_RED)
			{
				n->color = RB_BLACK;
				x->parent->color = RB_RED;
				ft_rb_right_rot(map, x->parent);
				n = x->parent->left;
			}
			del_ins_case2(map, &n, &x);
		}
	}
	x->color = RB_BLACK;
}
