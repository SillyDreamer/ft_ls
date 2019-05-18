/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:03:46 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/08 00:12:02 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_prefix(t_rb_node *root, void (*apply)(void *))
{
	if (root == NULL)
		return ;
	apply(root->data);
	ft_rb_prefix(root->left, apply);
	ft_rb_prefix(root->right, apply);
}
