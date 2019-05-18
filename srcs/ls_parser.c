/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:05:00 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/22 09:30:01 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	check_prioriry(t_opt *flags, char opt)
{
	if (opt == 'l' || opt == 'g')
	{
		if (F_G == '-')
			F_G = ON;
		F_ONE = OFF;
	}
	else if (opt == '1')
	{
		F_L = OFF;
		if (F_G == ON)
			F_G = '-';
		else
			F_G = OFF;
	}
}

static int	check_flags(t_opt *flags, char *str)
{
	char	opt;

	while ((opt = *(++str)))
		if (ft_strchr(OPTIONS, opt))
		{
			F_F = (opt == 'f') ? ON : F_F;
			F_L = (opt == 'l') ? ON : F_L;
			F_D = (opt == 'd') ? ON : F_D;
			F_R = (opt == 'r') ? ON : F_R;
			F_UR = (opt == 'R') ? ON : F_UR;
			F_G = (opt == 'g') ? ON : F_G;
			F_ONE = (opt == '1') ? ON : F_ONE;
			F_UG = (opt == 'G') ? ON : F_UG;
			check_prioriry(flags, opt);
			F_T = (opt == 't') ? ON : F_T;
			F_A = (opt == 'a') ? ON : F_A;
			F_U = (opt == 'u') ? ON : F_U;
			F_R = (F_F == ON) ? OFF : F_R;
			F_T = (F_F == ON) ? OFF : F_T;
			F_UR = (F_D == ON) ? OFF : F_UR;
		}
		else
			free_all(USAGE_ERR, &opt);
	return (1);
}

int			ls_parser(int ac, char **av, t_opt **flags)
{
	int		i;

	i = 0;
	if (!(*flags = (t_opt *)ft_memalloc(sizeof(t_opt))))
		free_all(MALL_ERR, 0);
	ft_memset(*flags, '0', sizeof(t_opt));
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			if (av[i][1] == '-' && av[i][2] == '\0')
				return (++i);
			else
				check_flags(*flags, av[i]);
		}
		else
			break ;
	}
	return (i);
}
