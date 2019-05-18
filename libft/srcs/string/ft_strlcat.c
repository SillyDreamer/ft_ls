/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:59:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:41:20 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*s;
	size_t		n;
	size_t		len;

	dest = dst;
	s = src;
	n = size;
	while (*dest != '\0' && n--)
		dest++;
	len = dest - dst;
	n = size - len;
	if (n == 0)
		return (ft_strlen(s) + len);
	while (*s != '\0')
	{
		if (n != 1)
		{
			*dest++ = *s;
			n--;
		}
		s++;
	}
	*dest = '\0';
	return (len + (s - src));
}
