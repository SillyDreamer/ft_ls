/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pro_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/22 08:11:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*vec_pro_push(t_vec **vec, void *c)
{
	void	*tmp;

	if (!(*vec))
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data = malloc(sizeof(void *) * ((*vec)->capacity * 2))))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, sizeof(void *) * (*vec)->total);
		free(tmp);
		(((void **)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	else
	{
		(((void **)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	return (*vec);
}
