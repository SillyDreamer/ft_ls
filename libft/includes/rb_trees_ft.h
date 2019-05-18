/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_trees_ft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:55:19 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/20 11:05:40 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREES_FT_H
# define RB_TREES_FT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum	e_color
{
	RB_BLACK,
	RB_RED
}				t_color;

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	int					key;
	t_color				color;
}				t_rb_node;

typedef struct	s_map
{
	t_rb_node	*root;
	t_rb_node	*nil;
	int			size;
}				t_map;

void			ft_rb_del_fix(t_map *map, t_rb_node *x);
void			ft_rb_del_node(t_map *map, int key);
t_rb_node		*ft_rb_find_node(t_map *map, int key);
void			ft_rb_free(t_rb_node *root);
void			ft_rb_infix(t_rb_node *root, void (*apply)(void *));
void			ft_rb_ins_fix(t_map *map, t_rb_node *x);
t_rb_node		*ft_rb_ins_node(t_map *map, int key);
void			ft_rb_left_rot(t_map *map, t_rb_node *x);
t_rb_node		*ft_rb_node_creat(t_map *map, int key);
void			ft_rb_prefix(t_rb_node *root, void (*apply)(void *));
void			ft_rb_print_key(t_rb_node *root);
void			ft_rb_right_rot(t_map *map, t_rb_node *x);
void			ft_rb_suffix(t_rb_node *root, void (*apply)(void *));
t_map			*ft_rb_tree_init(t_map *tree);
void			ft_rb_free_map(t_map **map);

#endif
