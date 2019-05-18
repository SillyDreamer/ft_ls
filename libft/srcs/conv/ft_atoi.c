/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:54:46 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/09 16:59:30 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/conv_ft.h"

static	int		ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f'
			|| c == '\v')
		return (1);
	return (0);
}

static size_t	ft_strilen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str) == '0')
		str++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	size_t			i;
	long long int	result;
	int				sign;
	int				j;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		((str[i++] == '-') ? (sign *= -1) : (sign *= 1));
	j = i;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = (result * 10) + str[i++] - 48;
	if (((size_t)result > PP && sign == 1 && ft_strilen(&str[j])
				>= 19) || (ft_strilen(&str[j]) > 19 && sign == 1))
		return (-1);
	if (((size_t)result > PP && sign == -1 && ft_strilen(&str[j])
				>= 19) || (ft_strilen(&str[j]) > 19 && sign == -1))
		return (0);
	result *= sign;
	return (result);
}
