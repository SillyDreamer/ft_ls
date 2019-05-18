/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:27:35 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:51:05 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_ft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr1;

	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while (n--)
	{
		if (*ptr != *ptr1)
			return (*ptr - *ptr1);
		ptr++;
		ptr1++;
	}
	return (0);
}
