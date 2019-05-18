/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:10:29 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/11 06:24:33 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

void	ft_rb_free(t_rb_node *root)
{
	if (!root)
		return ;
	ft_rb_free(root->left);
	ft_rb_free(root->right);
	free(root->data);
	root->data = NULL;
	free(root);
	root = NULL;
}
