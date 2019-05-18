/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:46:09 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:44:59 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strrchr(const char *s, int chr)
{
	char *ptr;
	char c;

	ptr = NULL;
	while (*s)
	{
		c = *s;
		if (c == (char)chr)
			ptr = (char *)s;
		s++;
	}
	if (chr == 0)
		return ((char *)s);
	return (ptr);
}
