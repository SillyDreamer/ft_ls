/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:05:00 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/03 17:15:21 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			print_bc_files(t_vec *vec, t_opt *flags, int i, t_len *lens)
{
	if (F_G == ON)
		ft_printf("%-*s%*d %-*s   %*d, %*d %s ", 12, ACCESS(i), lens->link_len,
				NLINKS(i), lens->grp_len, GID(i), lens->maj_len, MAJOR(RDEV(i)),
				lens->min_len, MINOR(RDEV(i)), (F_U == ON) ?
				timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
	else
		ft_printf("%-*s%*d %-*s  %-*s   %*d, %*d %s ", 12, ACCESS(i),
				lens->link_len, NLINKS(i), lens->uid_len, UID(i), lens->grp_len,
				GID(i), lens->maj_len, MAJOR(RDEV(i)), lens->min_len,
				MINOR(RDEV(i)), (F_U == ON) ?
				timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
}

static void			print_no_bc_files(t_vec *vec, t_opt *flags, int i,
																	t_len *lens)
{
	if (F_G == ON)
		ft_printf("%-*s%*d %-*s  %*d %s ", 12, ACCESS(i), lens->link_len,
				NLINKS(i), lens->grp_len, GID(i),
				lens->maj_len + lens->min_len + 3, (int)SIZE(i), (F_U == ON) ?
				timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
	else
		ft_printf("%-*s%*d %-*s  %-*s  %*d %s ", 12, ACCESS(i),
				lens->link_len, NLINKS(i), lens->uid_len, UID(i), lens->grp_len,
				GID(i), lens->maj_len + lens->min_len + 3, (int)SIZE(i),
				(F_U == ON) ? timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
}

static void			print_normal(t_vec *vec, t_opt *flags, int i, t_len *lens)
{
	if (F_G == ON)
		ft_printf("%-*s%*d %-*s  %*d %s ", 12, ACCESS(i), lens->link_len,
				NLINKS(i), lens->grp_len, GID(i), lens->fsize_len, (int)SIZE(i),
				(F_U == ON) ? timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
	else
		ft_printf("%-*s%*d %-*s  %-*s  %*d %s ", 12, ACCESS(i), lens->link_len,
				NLINKS(i), lens->uid_len, UID(i), lens->grp_len, GID(i),
				lens->fsize_len, (int)SIZE(i), (F_U == ON) ?
				timefix(ctime((long*)&ATIME(i)), (int)ATIME(i)) :
				timefix(ctime((long*)&MTIME(i)), (int)MTIME(i)));
}

static inline void	print_row(t_vec *vec, t_opt *flags, int i, t_len *lens)
{
	if (flags->bc == ON)
		if (TYPE(i) == 'b' || TYPE(i) == 'c')
			print_bc_files(vec, flags, i, lens);
		else
			print_no_bc_files(vec, flags, i, lens);
	else
		print_normal(vec, flags, i, lens);
}

void				print_long_format(t_vec *vec, t_opt *flags, int o)
{
	size_t	i;
	int		max;
	t_len	*lens;
	char	target_name[PATH_MAX + 1];

	i = -1;
	max = (int)max_name_len(vec);
	lens = get_str_size(vec, (size_t)-1);
	o == 1 && vec->total != 0 ? ft_printf("total %d\n", lens->total) : 0;
	while (++i < vec->total)
	{
		print_row(vec, flags, i, lens);
		F_UG == ON ? print_l_color(vec, (int)i, max, flags) :
		ft_printf("%s", NAME(i));
		if (TYPE(i) == 'l')
		{
			ft_bzero(target_name, PATH_MAX);
			readlink(PATH(i), target_name, PATH_MAX);
			ft_printf(" -> %s", target_name);
		}
		write(1, "\n", 1);
	}
}
