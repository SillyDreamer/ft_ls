/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 02:16:54 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/03 17:04:06 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <errno.h>
# include <sys/ioctl.h>
# include "../libft/includes/libft.h"
# include "../srcs/ft_printf/ft_printf.h"

# define OPTIONS "lRartufgdG1"

/*
** Structure for ls options;
** ur it's R (upper R)
** ug it's G (upper G)
** tty and bc used for better display
*/

typedef struct	s_opt
{
	char	l;
	char	ur;
	char	a;
	char	r;
	char	t;
	char	u;
	char	f;
	char	g;
	char	d;
	char	ug;
	char	one;
	char	bc;
	char	tty;
}				t_opt;

/*
** Structure with file stats
*/

typedef struct	s_file
{
	char		name[MAXNAMLEN + 1];
	char		access[12];
	char		path[PATH_MAX + 1];
	char		*uid;
	char		*gid;
	blkcnt_t	blocks;
	int64_t		mtime;
	int64_t		atime;
	size_t		namelen;
	off_t		size;
	dev_t		rdev;
	nlink_t		nlink;
}				t_file;

/*
** Structure for better display
*/

typedef	struct	s_len
{
	int link_len;
	int uid_len;
	int grp_len;
	int fsize_len;
	int maj_len;
	int min_len;
	int total;
}				t_len;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct winsize	t_win;

/*
** Defines for colors
*/

# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"

/*
** Defines for better code's readability
** F - means "FLAG"
*/

# define F_L flags->l
# define F_UR flags->ur
# define F_A flags->a
# define F_R flags->r
# define F_T flags->t
# define F_U flags->u
# define F_F flags->f
# define F_G flags->g
# define F_D flags->d
# define F_UG flags->ug
# define TTY flags->tty
# define F_ONE flags->one

/*
** Defines for files stats
*/

# define DATA(i) ((((void **)(vec->data))[i]))
# define NAME(i) (((t_file *)(((void **)(vec->data))[i]))->name)
# define NAMELEN(i) (((t_file *)(((void **)(vec->data))[i]))->namelen)
# define MTIME(i) (((t_file *)(((void **)(vec->data))[i]))->mtime)
# define ATIME(i) (((t_file *)(((void **)(vec->data))[i]))->atime)
# define TYPE(i) (((t_file *)(((void **)(vec->data))[i]))->access[0])
# define PATH(i) (((t_file *)(((void **)(vec->data))[i]))->path)
# define SIZE(i) (((t_file *)(((void **)(vec->data))[i]))->size)
# define ACCESS(i) (((t_file *)(((void **)(vec->data))[i]))->access)
# define GID(i) (((t_file *)(((void **)(vec->data))[i]))->gid)
# define UID(i) (((t_file *)(((void **)(vec->data))[i]))->uid)
# define NLINKS(i) (((t_file *)(((void **)(vec->data))[i]))->nlink)
# define BLOCKS(i) (((t_file *)(((void **)(vec->data))[i]))->blocks)
# define RDEV(i) (((t_file *)(((void **)(vec->data))[i]))->rdev)

# define MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINOR(x) ((int32_t)((x) & 0xffffff))

/*
** Magic numbers for errors or success
*/

# define MALL_ERR 2
# define USAGE_ERR 1
# define SUCCESS 0

/*
** Magic numbers for on/off flags
*/

# define ON '1'
# define OFF '0'

void			ls_errors(int num, char *c);
int				ls_parser(int ac, char **av, t_opt **flags);
int				ls_stat_parser(t_vec *vec, char *name, t_opt *opt, char *path);
void			ls_sort(t_vec *vec, t_opt *flags);
void			display_all(t_vec *vec, t_opt *flags);
void			display_name(t_vec *vec, t_opt *flags, int o);
t_vec			*readfunc(char *path, t_opt *flags);
void			display_first(t_vec *vec, t_opt *flags);
int				ft_printf(const char *restrict format, ...);
void			print_long_format(t_vec *vec, t_opt *flags, int o);
int				check_flags_and_set_path(t_file *file, t_opt *flags,
																t_stat *tmp);
int				parse_long_format(t_file *file, t_stat *tmp);
void			print_l_color(t_vec *vec, int i, int max, t_opt *flags);
t_len			*get_str_size(t_vec *vec, size_t i);
size_t			max_name_len(t_vec *vec);
char			*timefix(char *str, int timeint);
void			print_long_format(t_vec *vec, t_opt *flags, int o);
int				free_all(int num, char *c);
void			print_path(t_vec *vec, int i, int n);

#endif
