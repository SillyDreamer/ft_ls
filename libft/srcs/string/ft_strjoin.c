/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:22:36 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/15 02:53:20 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	fresh = (char *)ft_memalloc(len1 + len2 + 1);
	if (!fresh)
		return (NULL);
	ft_memcpy(fresh, s1, len1);
	ft_memcpy(fresh + len1, s2, len2);
	fresh[len1 + len2] = '\0';
	return (fresh);
}
