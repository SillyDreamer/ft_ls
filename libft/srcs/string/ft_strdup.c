/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:36:11 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/14 06:22:58 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char		*str;

	str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
