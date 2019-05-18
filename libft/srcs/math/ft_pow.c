/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 03:39:30 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:52:31 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math_ft.h"

double	ft_pow(double a, int pow)
{
	if (0 == pow)
		return (1);
	if (pow % 2 == 1)
		return (a * ft_pow(a, pow - 1));
	else
		return (ft_pow(a * a, pow / 2));
}
