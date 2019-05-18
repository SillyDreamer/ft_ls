/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:10:45 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/01/07 03:06:56 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"
#include "../../includes/memory_ft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	fresh = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!fresh)
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
