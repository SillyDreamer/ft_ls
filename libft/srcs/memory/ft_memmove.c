/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:17:08 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/15 01:57:26 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_ft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst8;
	char	*src8;
	size_t	d;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dst8 = (char *)dest + n;
		src8 = (char *)src + n;
		d = n;
		n /= 2;
		while (n--)
		{
			dst8 -= 2;
			src8 -= 2;
			dst8[1] = src8[1];
			dst8[0] = src8[0];
		}
		if (d & 1)
			((char *)dest)[0] = ((char *)src)[0];
	}
	return (dest);
}
