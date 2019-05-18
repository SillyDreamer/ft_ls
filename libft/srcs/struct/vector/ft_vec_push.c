/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/22 08:11:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*ft_vec_push(t_vec **vec, char c)
{
	void	*tmp;

	if (!(*vec))
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data = malloc((*vec)->capacity * 2)))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, (*vec)->total);
		free(tmp);
		(((char *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	else
	{
		(((char *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	return (*vec);
}
