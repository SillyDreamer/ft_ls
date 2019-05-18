/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:50:49 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:44:36 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		n;

	if (*to_find == '\0')
		return ((char *)str);
	n = ft_strlen(to_find);
	if (!str)
		i = (int)(*str);
	i = 0;
	if (n > (int)len)
		return (NULL);
	while (*(str + i) && i <= (int)len - n)
	{
		if (ft_strncmp(&(str[i]), to_find, n) == 0)
			return ((char *)(&(str[i])));
		i++;
	}
	return (NULL);
}
