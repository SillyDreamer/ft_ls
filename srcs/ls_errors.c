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

/*
** Function to check program's errors
** num = 1 - means "flags error"
** num = 2 - means "file/directory not found"
** num = 3 - means "malloc error"
*/

void	ls_errors(int num, char *c)
{
	if (num == 1)
	{
		write(2, "ls: illegal option -- ", 22);
		write(2, c, 1);
		write(2, "\n", 1);
		write(2, "usage: ls [-GRadfglrtu1] [file ...]\n", 36);
	}
	if (num == 2)
		write(2, "malloc error\n", 13);
	exit(num);
}
