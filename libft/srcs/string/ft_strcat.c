/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:36:42 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/21 12:59:49 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char		*d;
	const char	*s;

	d = dest - 1;
	s = src - 1;
	while (*++d)
		;
	--d;
	while ((*++d = *++s))
		;
	return (dest);
}
