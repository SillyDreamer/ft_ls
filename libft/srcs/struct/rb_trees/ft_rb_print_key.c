/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:07:57 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 22:29:44 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_rb_print_key(t_rb_node *root)
{
	if (root == NULL)
		return ;
	ft_putnbr(root->key);
	ft_rb_print_key(root->left);
	ft_rb_print_key(root->right);
}
