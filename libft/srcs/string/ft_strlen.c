/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 07:52:09 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/07 22:59:55 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

size_t	ft_strlen(const char *str)
{
	unsigned	x;
	size_t		len;

	len = 0;
	while (1)
	{
		x = *(unsigned *)str;
		if ((x & 0xFF) == 0)
			return (len);
		if ((x & 0xFF00) == 0)
			return (len + 1);
		if ((x & 0xFF0000) == 0)
			return (len + 2);
		if ((x & 0xFF000000) == 0)
			return (len + 3);
		str += 4;
		len += 4;
	}
}
