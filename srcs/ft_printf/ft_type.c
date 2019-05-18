/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 07:49:16 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/01/28 22:25:50 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_s(t_var *var, va_list args, int j, int k)
{
	char	*s;

	if (var->flagmin == 1)
	{
		s = va_arg(args, char *);
		ft_putstr(s);
		while (k++ < var->arr[j] - (int)ft_strlen(s))
			ft_putstr(" ");
		var->flagmin = 0;
	}
	else if (var->flagnomin == 1)
	{
		s = va_arg(args, char*);
		while ((unsigned long)k++ < var->arr[j] - ft_strlen(s))
			ft_putstr(" ");
		ft_putstr(s);
		var->flagnomin = 0;
	}
	else
	{
		s = va_arg(args, char *);
		ft_putstr(s);
	}
}

void		type_d(t_var *var, va_list args, int j, int k)
{
	int		d;

	if (var->flagmin == 1)
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		while (k++ < var->arr[j] - nbrlen(d))
			ft_putstr(" ");
		var->flagmin = 0;
	}
	else if (var->flagnomin == 1)
	{
		d = va_arg(args, int);
		while (k++ < var->arr[j] - nbrlen(d))
			ft_putstr(" ");
		ft_putnbr(d);
		var->flagnomin = 0;
	}
	else
	{
		d = va_arg(args, int);
		ft_putnbr(d);
	}
}

void		type_c(t_var *var, va_list args, int j, int k)
{
	char	c;

	if (var->flagmin == 1)
	{
		c = va_arg(args, int);
		ft_putchar(c);
		while (k++ < var->arr[j] - 1)
			ft_putstr(" ");
		var->flagmin = 0;
	}
	else if (var->flagnomin == 1)
	{
		c = va_arg(args, int);
		while (k++ < var->arr[j] - 1)
			ft_putstr(" ");
		ft_putchar(c);
		var->flagnomin = 0;
	}
	else
	{
		c = va_arg(args, int);
		ft_putchar(c);
	}
}
