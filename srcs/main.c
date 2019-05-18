/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:05:00 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/22 09:30:01 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		free_all(int num, char *c)
{
	size_t i;

	i = -1;
	while (++i < g_mass->total)
		free(((void **)(g_mass->data))[i]);
	free(g_mass->data);
	free(g_mass);
	if (num == 1)
	{
		write(2, "ft_ls: illegal option -- ", 25);
		write(2, c, 1);
		write(2, "\n", 1);
		write(2, "usage: ft_ls [-GRadfglrtu] [file ...]\n", 38);
	}
	if (num == 2)
		write(2, "malloc error\n", 13);
	if (num)
		exit(num);
	return (0);
}

int		main(int ac, char **av)
{
	t_opt	*flags;
	t_vec	*vec;

	if (!(g_mass = vec_pro_init(16)))
		ls_errors(MALL_ERR, 0);
	av += ls_parser(ac, av, &flags);
	if (isatty(STDOUT_FILENO))
		flags->tty = ON;
	if (!(vec = ft_ls_vec_init(2)))
		free_all(MALL_ERR, 0);
	if (*av == NULL)
		ls_stat_parser(vec, ".", flags, "");
	else
		while (*av)
			ls_stat_parser(vec, *av++, flags, "");
	ls_sort(vec, flags);
	display_first(vec, flags);
	if (F_D == OFF)
		display_all(vec, flags);
	free_all(SUCCESS, 0);
	return (0);
}
