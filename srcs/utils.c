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

int			check_flags_and_set_path(t_file *file, t_opt *flags, t_stat *tmp)
{
	if (file->access[0] == 'd' || file->access[0] == 'l')
	{
		file->path[0] && ft_strcmp(file->path, "/") ?
												ft_strcat(file->path, "/") : 0;
		ft_strcat(file->path, file->name);
	}
	if (F_L == ON || F_G == ON)
	{
		if (!(parse_long_format(file, tmp)))
			return (0);
	}
	else if (F_T == ON || F_U == ON)
	{
		file->mtime = tmp->st_mtimespec.tv_sec;
		file->atime = tmp->st_atimespec.tv_sec;
	}
	return (1);
}

t_len		*get_str_size(t_vec *vec, size_t i)
{
	t_len	*lens;
	int		len;

	if (!(lens = (t_len *)ft_memalloc(sizeof(t_len))))
		free_all(MALL_ERR, 0);
	while (++i < vec->total)
	{
		lens->total += BLOCKS(i);
		len = ft_int_len(SIZE(i));
		lens->fsize_len = len >= lens->fsize_len ? len : lens->fsize_len;
		len = (int)ft_strlen(GID(i));
		lens->grp_len = len >= lens->grp_len ? len : lens->grp_len;
		len = ft_int_len(NLINKS(i));
		lens->link_len = len >= lens->link_len ? len : lens->link_len;
		len = (int)ft_strlen(UID(i));
		lens->uid_len = len >= lens->uid_len ? len : lens->uid_len;
		if (TYPE(i) == 'b' || TYPE(i) == 'c')
		{
			len = ft_int_len(MAJOR(RDEV(i)));
			lens->maj_len = len >= lens->maj_len ? len : lens->maj_len;
			len = ft_int_len(MINOR(RDEV(i)));
			lens->min_len = len >= lens->min_len ? len : lens->min_len;
		}
	}
	return (lens);
}

size_t		max_name_len(t_vec *vec)
{
	size_t	i;
	size_t	max;

	i = -1;
	max = 0;
	while (++i < vec->total)
	{
		if (NAMELEN(i) > max)
			max = NAMELEN(i);
	}
	return (max);
}

char		*timefix(char *str, int timeint)
{
	char	*s;

	if (timeint > (time(NULL) - 15778463))
	{
		if (!(str = ft_strsub(str, 4, ft_strlen(str) - 13)))
			free_all(MALL_ERR, 0);
	}
	else
	{
		if (!(s = ft_strsub(str, 4, ft_strlen(str) - 18)))
			free_all(MALL_ERR, 0);
		if (!(str = ft_strjoin(s, ft_strsub(str, 19, 5))))
			free_all(MALL_ERR, 0);
	}
	return (str);
}
