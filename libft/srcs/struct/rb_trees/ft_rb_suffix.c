/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:06:31 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/08 00:11:04 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_suffix(t_rb_node *root, void (*apply)(void *))
{
	if (root == NULL)
		return ;
	ft_rb_suffix(root->left, apply);
	ft_rb_suffix(root->right, apply);
	apply(root->data);
}
