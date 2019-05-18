/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:38:37 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/14 06:39:44 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	const char	*s;
	char		*d;

	s = src - 1;
	d = dest - 1;
	while (*++s)
		*++d = *s;
	*++d = '\0';
	return (dest);
}
