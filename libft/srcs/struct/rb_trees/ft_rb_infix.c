/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_infix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:05:24 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:24:04 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_infix(t_rb_node *root, void (*apply)(void *))
{
	if (root == NULL)
		return ;
	ft_rb_infix(root->left, apply);
	apply(root->data);
	ft_rb_infix(root->right, apply);
}
