/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:57:29 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/14 04:12:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_ft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	if (len != 0)
	{
		d = b;
		while (len--)
			*d++ = (unsigned char)c;
	}
	return (b);
}
