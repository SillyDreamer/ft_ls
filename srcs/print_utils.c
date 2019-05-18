/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 02:20:35 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/01/29 04:31:08 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_l_color(t_vec *vec, int i, int max, t_opt *flags)
{
	char *acc;
	char type;

	acc = ACCESS(i);
	type = TYPE(i);
	type == 'd' ? ft_printf(BLU "%-*s " NRM, max, NAME(i)) : 0;
	if (type == 'l')
		ft_printf(MAG "%-*s " NRM, (F_G == ON || F_L == ON) ? 0 : max, NAME(i));
	type == 'c' ? ft_printf(YEL "%-*s " NRM, max, NAME(i)) : 0;
	type == 'b' ? ft_printf(GRN "%-*s " NRM, max, NAME(i)) : 0;
	type == 'p' ? ft_printf(CYN "%-*s " NRM, max, NAME(i)) : 0;
	if (type == '-' && (acc[3] == 'x' || acc[3] == 's' || acc[6] == 'x'
							|| acc[6] == 's' || acc[9] == 'x' || acc[9] == 't'))
		ft_printf(RED "%-*s " NRM, max, NAME(i));
	else if (type == '-')
		ft_printf("%-*s ", max, NAME(i));
}

void	print_path(t_vec *vec, int i, int n)
{
	if (vec->total != 1 || ft_strcmp(PATH(i), NAME(i)))
	{
		if (n != 0)
			write(1, "\n", 1);
		ft_printf("%s:\n", PATH(i));
	}
}
