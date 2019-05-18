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

inline static void	parse_file_mode(t_file *file, mode_t st_mode)
{
	char *acc;

	acc = file->access;
	acc[1] = ((st_mode & S_IRUSR) ? 'r' : '-');
	acc[2] = ((st_mode & S_IWUSR) ? 'w' : '-');
	acc[4] = ((st_mode & S_IRGRP) ? 'r' : '-');
	acc[5] = ((st_mode & S_IWGRP) ? 'w' : '-');
	acc[7] = ((st_mode & S_IROTH) ? 'r' : '-');
	acc[8] = ((st_mode & S_IWOTH) ? 'w' : '-');
}

static int			parse_acl(t_file *file)
{
	acl_t		acl;
	acl_entry_t	dummy;
	char		full_path[PATH_MAX];

	ft_bzero(full_path, PATH_MAX);
	ft_memcpy(full_path, file->path, ft_strlen(file->path));
	if (file->access[0] != 'd' && file->access[0] != 'l')
	{
		ft_strcat(full_path, "/");
		ft_strcat(full_path, file->name);
	}
	acl = acl_get_link_np(full_path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (listxattr(full_path, NULL, 0, XATTR_NOFOLLOW) > 0)
		file->access[10] = '@';
	else if (acl != NULL)
		file->access[10] = '+';
	acl_free(acl);
	return (1);
}

int					parse_long_format(t_file *file, t_stat *tmp)
{
	if (!(file->gid = ft_strjoin("", getgrgid(tmp->st_gid)->gr_name)))
		free_all(MALL_ERR, 0);
	if (!(file->uid = ft_strjoin("", getpwuid(tmp->st_uid)->pw_name)))
		free_all(MALL_ERR, 0);
	file->nlink = tmp->st_nlink;
	file->rdev = tmp->st_rdev;
	file->size = tmp->st_size;
	file->blocks = tmp->st_blocks;
	file->mtime = tmp->st_mtimespec.tv_sec;
	file->atime = tmp->st_atimespec.tv_sec;
	parse_file_mode(file, tmp->st_mode);
	if (!(parse_acl(file)))
		return (0);
	return (1);
}

static void			parse_file_type(t_file *file, mode_t st_mode)
{
	char *acc;

	acc = file->access;
	acc[0] = (S_ISBLK(st_mode) ? 'b' : acc[0]);
	acc[0] = (S_ISCHR(st_mode) ? 'c' : acc[0]);
	acc[0] = (S_ISDIR(st_mode) ? 'd' : acc[0]);
	acc[0] = (S_ISFIFO(st_mode) ? 'p' : acc[0]);
	acc[0] = (S_ISLNK(st_mode) ? 'l' : acc[0]);
	acc[0] = (S_ISSOCK(st_mode) ? 's' : acc[0]);
	acc[0] = (S_ISREG(st_mode) ? '-' : acc[0]);
	acc[3] = ((st_mode & S_IXUSR) ? 'x' : '-');
	acc[6] = ((st_mode & S_IXGRP) ? 'x' : '-');
	acc[9] = ((st_mode & S_IXOTH) ? 'x' : '-');
	if (st_mode & S_ISUID)
		acc[3] = (acc[3] == '-' ? 'S' : 's');
	if (st_mode & S_ISGID)
		acc[6] = (acc[6] == '-' ? 'S' : 's');
	if (st_mode & S_ISVTX)
		acc[9] = (acc[9] == '-' ? 'T' : 't');
}

int					ls_stat_parser(t_vec *vec, char *name,
													t_opt *flags, char *path)
{
	t_stat	tmp;
	t_file	*file;
	char	fpath[PATH_MAX + 1];

	if (!(file = (t_file *)ft_memalloc(sizeof(t_file))))
		return (free_all(MALL_ERR, 0));
	if ((file->namelen = ft_strlen(name)) > MAXNAMLEN)
	{
		ft_printf("ft_ls: %s: File name too long\n", name);
		return (2);
	}
	ft_memcpy(file->name, name, file->namelen);
	ft_strcat(file->path, path);
	ft_bzero(fpath, PATH_MAX);
	file->path[0] ? ft_strcat(fpath, file->path) && ft_strcat(fpath, "/") : 0;
	if ((lstat(ft_strcat(fpath, name), &tmp)) == -1)
		return (ft_printf("ft_ls: %s: %s\n", name, strerror(errno)));
	parse_file_type(file, tmp.st_mode);
	file->access[0] == 'b' || file->access[0] == 'c' ? flags->bc = ON : 0;
	if (!(check_flags_and_set_path(file, flags, &tmp)))
		return (0);
	(!(ft_ls_vec_push(&vec, file))) ? free_all(MALL_ERR, 0) : 0;
	return (0);
}
