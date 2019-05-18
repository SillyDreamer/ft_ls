/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:23:18 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/15 01:58:38 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_ft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	ssize_t			*dst1;
	const ssize_t	*src1;
	char			*dst2;
	const char		*src2;
	size_t			n;

	if (dest == src)
		return (dest);
	dst1 = (ssize_t *)dest;
	src1 = (const ssize_t *)src;
	n = sizeof(ssize_t);
	while (count >= n)
	{
		*dst1++ = *src1++;
		count -= n;
	}
	dst2 = (char *)dst1;
	src2 = (const char *)src1;
	while (count--)
		*dst2++ = *src2++;
	return (dest);
}
