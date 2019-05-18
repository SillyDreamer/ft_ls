/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:05:00 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/01/07 02:51:46 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static int		line_break_find(char **line, const t_rb_node *tmp,
		ssize_t ret, t_vec **vec)
{
	POS = 0;
	while (BUF[POS] != '\n' && POS != ret)
		ft_vec_push(vec, (BUF[POS++]));
	if (BUF[POS] == '\n' || (POS == ret && ret < BUFF_SIZE))
	{
		ft_vec_push(vec, 0);
		*line = (*vec)->data;
		free(*vec);
		++POS;
		((t_buf *)tmp->data)->cap = ret;
		return (1);
	}
	return (0);
}

static int		ft_free(t_vec **vec, t_map **map, t_rb_node *tmp, const int fd)
{
	if (vec && map && tmp)
		free((*vec)->data);
	if (vec)
		free(*vec);
	if (map)
		free(BUF);
	if (tmp)
		ft_rb_del_node(*map, fd);
	if (map && (*map)->size == 0)
	{
		free((*map)->nil);
		free(*map);
		*map = NULL;
	}
	return (0);
}

static t_buf	*ft_buf_init(size_t cap)
{
	t_buf	*buf;

	if (!(buf = (t_buf *)malloc(sizeof(t_buf))))
		return (0);
	if (!(buf->buf = (char *)malloc(sizeof(char) * (cap + 1))))
	{
		free(buf);
		return (0);
	}
	buf->cap = cap;
	buf->pos = 0;
	return (buf);
}

static int		push_back(char **line, t_map *map, t_rb_node *tmp, t_vec **vec)
{
	if (!(*vec = ft_vec_init(2)))
		return (ft_free(NULL, &map, tmp, tmp->key) - 1);
	if (tmp->data == map->nil || tmp->data == NULL)
	{
		if (!(tmp->data = ft_buf_init(BUFF_SIZE)))
			return (ft_free(NULL, &map, tmp, tmp->key) - 1);
	}
	else if (POS != ((t_buf *)tmp->data)->cap)
	{
		while (POS < ((t_buf *)tmp->data)->cap)
		{
			if (BUF[POS] == '\n')
			{
				if (!(ft_vec_push(vec, '\0') && (*line = (*vec)->data)))
					return (ft_free(vec, &map, tmp, tmp->key) - 1);
				free((*vec));
				return (++POS || 1);
			}
			if (!(ft_vec_push(vec, (BUF[POS++]))))
				return (ft_free(vec, &map, tmp, tmp->key));
		}
	}
	return (3);
}

int				get_next_line(const int fd, char **line)
{
	static t_map	*map = NULL;
	t_rb_node		*tmp;
	ssize_t			ret;
	t_vec			*vec;
	int				l;

	if (!line || fd == -1 || (map == NULL && !(map = ft_rb_tree_init(map))))
		return (-1);
	*line = NULL;
	if (!(tmp = ft_rb_ins_node(map, fd)))
		return (ft_free(NULL, &map, NULL, fd) - 1);
	if ((l = push_back(line, map, tmp, &vec)) == 1 || l == -1)
		return (l);
	while ((ret = read(fd, BUF, BUFF_SIZE)) > 0)
		if ((!(BUF[ret] = '\0')) && line_break_find(line, tmp, ret, &vec))
			return (1);
	if (ret == 0 && vec->total == 0)
		return (ft_free(&vec, &map, tmp, fd));
	else if (vec->total != 0)
	{
		ft_vec_push(&vec, 0) && (*line = vec->data) && (++POS);
		return (ft_free(&vec, 0, 0, fd) + 1);
	}
	return (ft_free(&vec, &map, tmp, fd) - 1);
}
