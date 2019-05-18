/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_ins_fix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:01:33 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:25:13 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

static void	ft_insertion_case_1(t_rb_node *y, t_rb_node **x, t_map **map)
{
	if (y != (*map)->nil && y->color == RB_RED)
	{
		(*x)->parent->color = RB_BLACK;
		y->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		(*x) = (*x)->parent->parent;
	}
	else
	{
		if (*x == (*x)->parent->right)
		{
			*x = (*x)->parent;
			ft_rb_left_rot(*map, *x);
		}
		(*x)->parent->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		ft_rb_right_rot(*map, (*x)->parent->parent);
	}
}

static void	ft_insertion_case_2(t_rb_node *y, t_rb_node **x, t_map **map)
{
	if (y != (*map)->nil && (y)->color == RB_RED)
	{
		(*x)->parent->color = RB_BLACK;
		y->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		(*x) = (*x)->parent->parent;
	}
	else
	{
		if ((*x) == (*x)->parent->left)
		{
			(*x) = (*x)->parent;
			ft_rb_right_rot(*map, *x);
		}
		(*x)->parent->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		ft_rb_left_rot(*map, (*x)->parent->parent);
	}
}

void		ft_rb_ins_fix(t_map *map, t_rb_node *x)
{
	t_rb_node	*y;

	while (x != map->root && x->parent->color == RB_RED)
	{
		if (x->parent == x->parent->parent->left)
		{
			y = x->parent->parent->right;
			ft_insertion_case_1(y, &x, &map);
		}
		else if (x->parent == x->parent->parent->right)
		{
			y = x->parent->parent->left;
			ft_insertion_case_2(y, &x, &map);
		}
	}
	map->root->color = RB_BLACK;
}
