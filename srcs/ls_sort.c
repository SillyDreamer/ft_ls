/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stat_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:05:00 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/22 09:30:01 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

inline static void	q_sort_mtime(void **data, int len, short int r)
{
	int	i;
	int	pvt;

	i = -1;
	pvt = 0;
	if (len <= 1)
		return ;
	--len;
	while (++i < len)
	{
		if (((((t_file *)(((data))[i]))->mtime * r) >
									(((t_file *)(((data))[len]))->mtime * r)))
			ft_swap(&((((data))[i])), &((((data))[pvt++])));
		else if (((((t_file *)(((data))[i]))->mtime) ==
										(((t_file *)(((data))[len]))->mtime))
							&& r * ft_strcmp((((t_file *)(((data))[i]))->name),
									(((t_file *)(((data))[len]))->name)) < 0)
			ft_swap(&((((data))[i])), &((((data))[pvt++])));
	}
	ft_swap(&((((data))[pvt])), &((((data))[len])));
	q_sort_mtime(data, pvt++, r);
	q_sort_mtime(data + pvt, len + 1 - pvt, r);
}

inline static void	q_sort_atime(void **data, int len, short int r)
{
	int	i;
	int	pvt;

	i = -1;
	pvt = 0;
	if (len <= 1)
		return ;
	--len;
	while (++i < len)
	{
		if (((((t_file *)(((data))[i]))->atime * r) >
									(((t_file *)(((data))[len]))->atime * r)))
			ft_swap(&((((data))[i])), &((((data))[pvt++])));
		else if (((((t_file *)(((data))[i]))->atime) ==
					(((t_file *)(((data))[len]))->atime))
					&& r * ft_strcmp((((t_file *)(((data))[i]))->name),
									(((t_file *)(((data))[len]))->name)) < 0)
			ft_swap(&((((data))[i])), &((((data))[pvt++])));
	}
	ft_swap(&((((data))[pvt])), &((((data))[len])));
	q_sort_atime(data, pvt++, r);
	q_sort_atime(data + pvt, len + 1 - pvt, r);
}

inline static void	q_sort_name(void **data, int len, short int r)
{
	int	i;
	int	pvt;

	i = -1;
	pvt = 0;
	if (len <= 1)
		return ;
	--len;
	while (++i < len)
	{
		if (r * ft_strcmp((((t_file *)(((data))[i]))->name),
									(((t_file *)(((data))[len]))->name)) < 0)
			ft_swap(&((((data))[i])), &((((data))[pvt++])));
	}
	ft_swap(&((((data))[pvt])), &((((data))[len])));
	q_sort_name(data, pvt++, r);
	q_sort_name(data + pvt, len + 1 - pvt, r);
}

void				ls_sort(t_vec *vec, t_opt *flags)
{
	if (F_T == ON)
	{
		if (F_U == ON)
			q_sort_atime(vec->data, (int)vec->total, F_R == ON ? -1 : 1);
		else
			q_sort_mtime(vec->data, (int)vec->total, F_R == ON ? -1 : 1);
	}
	else if (F_F != ON)
		q_sort_name(vec->data, (int)vec->total, F_R == ON ? -1 : 1);
}
