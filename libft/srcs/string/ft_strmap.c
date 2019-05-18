/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:15:55 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:42:24 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	fresh = ft_strnew(ft_strlen(s));
	if (fresh)
	{
		while (s[i])
		{
			fresh[i] = f(s[i]);
			i++;
		}
	}
	return (fresh);
}
