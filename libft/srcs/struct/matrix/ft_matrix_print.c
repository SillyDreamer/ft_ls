/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 03:35:46 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 23:05:08 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_matrix_print(t_matrix *mass)
{
	size_t	i;
	size_t	j;
	int		k;
	int		len;

	i = -1;
	len = ft_int_len((int)ft_matrix_max(mass));
	while (++i < mass->row)
	{
		j = -1;
		while (++j < mass->col)
		{
			k = ft_int_len((mass->matrix)[i][j]);
			ft_putchar('[');
			while (k++ < len)
				ft_putchar(' ');
			ft_putstr(ft_ftoa(mass->matrix[i][j], 2));
			ft_putchar(']');
		}
		ft_putchar('\n');
	}
}
