/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:48:12 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:43:06 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (dest[i] != '\0')
		i++;
	while (src[++j] != '\0' && n--)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
