/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:49:55 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:45:14 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

static void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char		*ft_strreverse(char *str)
{
	char	*start;
	char	*end;

	if (!str)
		return (NULL);
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
