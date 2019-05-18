/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:51:48 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:47:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

static int	ft_sspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *str)
{
	char	*fresh;
	int		i;
	int		l;

	if (!str)
		return (NULL);
	l = ft_strlen(str);
	i = -1;
	while (ft_sspace(str[l - 1]))
		l--;
	while (ft_sspace(str[++i]))
		l--;
	l = ((l < 0) ? 0 : l);
	fresh = (char *)malloc(sizeof(char) * (l + 1));
	if (!fresh)
		return (NULL);
	str += i;
	i = -1;
	while (++i < l)
		fresh[i] = *str++;
	fresh[i] = '\0';
	return (fresh);
}
