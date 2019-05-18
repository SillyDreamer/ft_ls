/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:46:53 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/03 17:13:20 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_atoi2(const char *str)
{
	int sign;
	int i;
	int n;

	sign = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] <= '9' && str[i + 1] >= '0')
	{
		i++;
	}
	if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	return (n * sign);
}

int				nbrlen(int d)
{
	int k;

	k = 0;
	while ((d / 10) > 0)
	{
		k++;
		d = d / 10;
	}
	return (k + 1);
}

static void		type(va_list args, char format, t_var *var, int j)
{
	if (format == 's')
		type_s(var, args, j, 0);
	else if (format == 'd')
		type_d(var, args, j, 0);
	else if (format == 'c')
		type_c(var, args, j, 0);
}

int				ft_printf(const char *s, ...)
{
	t_var	*var;
	va_list	args;

	var = (t_var *)ft_memalloc(sizeof(t_var) * 1);
	var->j = 0;
	var->i = -1;
	va_start(args, s);
	while (s[++var->i])
		if (s[var->i] == '%')
		{
			var->i++;
			s[var->i] == '-' ? specifier_minus(var, args, s) : 0;
			s[var->i] == '*' ? specifier_star(var, args) : 0;
			if (s[var->i] == 'c' || s[var->i] == 'd' || s[var->i] == 's')
			{
				type(args, s[var->i], var, var->j - 1);
				var->arr[var->j] ? var->j++ : 0;
			}
			else
				ft_putchar(s[var->i]);
		}
		else
			ft_putchar(s[var->i]);
	va_end(args);
	return (42);
}
