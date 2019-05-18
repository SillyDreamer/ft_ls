/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 01:00:40 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 22:20:16 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/conv_ft.h"
#include "../../includes/math_ft.h"

static void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char	*ft_strrev(char *str)
{
	char *start;
	char *end;

	start = str;
	end = str;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	while (start < end)
	{
		ft_swap(start, end);
		start++;
		end--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*mass;
	int		i;
	int		flag;

	mass = (char *)malloc(sizeof(char) * (ft_int_len(n) + 1));
	if (!mass)
		return (NULL);
	i = ((n == 0) ? 1 : 0);
	mass[0] = '0';
	flag = ((n < 0) ? -1 : 1);
	while (n != 0)
	{
		mass[i++] = (n % 10) * flag + '0';
		n = n / 10;
	}
	if (flag == -1)
	{
		mass[i] = '-';
		mass[i + 1] = '\0';
	}
	else
		mass[i] = '\0';
	mass = ft_strrev(mass);
	return (mass);
}
