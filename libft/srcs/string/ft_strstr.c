/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:48:24 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/15 02:59:32 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t tmp;
	size_t index_find;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		index_find = 0;
		if (str[i] == to_find[index_find])
		{
			tmp = i;
			while (str[i] == to_find[index_find])
			{
				if (to_find[index_find + 1] == '\0')
					return ((char *)&str[tmp]);
				index_find++;
				i++;
			}
			i = tmp;
		}
		i++;
	}
	return (NULL);
}
