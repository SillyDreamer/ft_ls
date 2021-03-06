/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:57:15 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:49:27 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put_ft.h"

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
			write(1, s++, 1);
	}
}
