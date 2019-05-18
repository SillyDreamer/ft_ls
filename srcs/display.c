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

void		print_in_tty(t_vec *vec, t_opt *flags, size_t max, size_t tmp)
{
	size_t	i;
	size_t	print_num;
	t_win	win;
	size_t	row_num;
	size_t	step;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	win.ws_col = win.ws_col > 80 ? win.ws_col - (short)(max + 4) : win.ws_col;
	row_num = (size_t)((double)tmp / win.ws_col) + (tmp % win.ws_col != 0);
	step = 0;
	print_num = row_num;
	while (row_num--)
	{
		i = step++;
		while (i < vec->total)
		{
			if (F_UG == ON)
				print_l_color(vec, (int)i, (int)max, flags);
			else
				(i + print_num >= vec->total) ? ft_printf("%s", NAME(i)) :
										ft_printf("%-*s\t", (int)max, NAME(i));
			i += print_num;
		}
		write(1, "\n", 1);
	}
}

void		display_name(t_vec *vec, t_opt *flags, int o)
{
	size_t	i;
	int		max;
	size_t	str_len;

	if (F_L == ON || F_G == ON)
		print_long_format(vec, flags, o);
	else if (TTY == OFF || F_ONE == ON)
	{
		i = -1;
		while (++i < vec->total)
			if (TTY == OFF)
				ft_printf("%s\n", NAME(i));
			else if (F_ONE == ON)
			{
				F_UG == ON ? print_l_color(vec, (int)i, 1, flags) :
													ft_printf("%s", NAME(i));
				write(1, "\n", 1);
			}
	}
	else
	{
		max = (int)max_name_len(vec);
		str_len = (max + (F_UG == ON ? 1 : 4)) * vec->total;
		print_in_tty(vec, flags, (size_t)max, str_len);
	}
}

void		display_first(t_vec *vec, t_opt *flags)
{
	size_t		i;
	t_vec		*tmp;
	DIR			*fd;

	i = -1;
	(!(tmp = ft_ls_vec_init(2))) ? free_all(MALL_ERR, 0) : 0;
	if (F_D == ON)
		while (++i < vec->total)
			(!(ft_ls_vec_push(&tmp, DATA(i)))) ? free_all(MALL_ERR, 0) : 0;
	else
	{
		while (++i < vec->total)
		{
			fd = 0;
			if (TYPE(i) == 'd' || ((fd = opendir(NAME(i)))
												&& F_L == OFF && F_G == OFF))
			{
				fd != 0 ? closedir(fd) : 0;
				continue;
			}
			(!(ft_ls_vec_push(&tmp, DATA(i)))) ? free_all(MALL_ERR, 0) : 0;
		}
	}
	if (tmp->total != 0)
		display_name(tmp, flags, 0);
}

t_vec		*readfunc(char *path, t_opt *flags)
{
	DIR			*fd;
	t_vec		*vec;
	t_dirent	*ret;

	if (!(fd = opendir(path)))
		return (NULL);
	if (!(vec = ft_ls_vec_init(2)))
		free_all(MALL_ERR, 0);
	flags->bc = OFF;
	while ((ret = readdir(fd)))
	{
		if (ret->d_type == 2 || ret->d_type == 6)
			flags->bc = ON;
		if (F_A == OFF && F_F == OFF && ret->d_name[0] == '.')
			continue ;
		ls_stat_parser(vec, ret->d_name, flags, path);
	}
	ls_sort(vec, flags);
	closedir(fd);
	return (vec);
}

void		display_all(t_vec *vec, t_opt *flags)
{
	int			i;
	t_vec		*data;
	int			tot;
	DIR			*fd;
	static int	n = 0;

	i = -1;
	tot = (int)vec->total;
	while (++i < tot && !(fd = 0))
	{
		if (tot != 1 && (!ft_strcmp(NAME(i), ".") || !ft_strcmp(NAME(i), "..")))
			continue;
		if (TYPE(i) ^ 'd' && (F_L == ON || F_G == ON ||
													!(fd = opendir(NAME(i)))))
			continue;
		fd != 0 ? closedir(fd) : 0;
		print_path(vec, i, n++);
		if (!(data = readfunc(PATH(i), flags)))
		{
			ft_printf("ft_ls: %s: %s\n", NAME(i), strerror(errno));
			continue;
		}
		display_name(data, flags, 1);
		F_UR == ON ? display_all(data, flags) : 0;
	}
}
