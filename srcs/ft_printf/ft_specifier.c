/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 22:26:46 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/01/28 22:27:35 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		specifier_star(t_var *var, va_list args)
{
	var->arr[var->j] = va_arg(args, int);
	var->i++;
	var->j++;
	var->flagnomin = 1;
}

void		specifier_minus(t_var *var, va_list args, const char *restrict s)
{
	var->flagmin = 1;
	if (s[++var->i] == '*')
	{
		var->arr[var->j] = va_arg(args, int);
		var->i++;
		var->j++;
	}
	else
	{
		var->arr[var->j] = ft_atoi2(&s[var->i]);
		var->j++;
		while (s[var->i] != 'd' && s[var->i]
		!= 's' && s[var->i] != 'c')
			var->i++;
	}
}
