/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 07:47:33 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/01/28 22:27:32 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../../includes/ft_ls.h"

typedef struct	s_var
{
	int			flagmin;
	int			arr[6];
	int			j;
	int			i;
	int			flagnomin;

}				t_var;

int				ft_printf(const char *format, ...);
int				nbrlen(int d);
void			type_s(t_var *var, va_list args, int j, int k);
void			type_c(t_var *var, va_list args, int j, int k);
void			type_d(t_var *var, va_list args, int j, int k);
void			specifier_minus(t_var *var, va_list args,
														const char *restrict s);
void			specifier_star(t_var *var, va_list args);
int				ft_atoi2(const char *str);

#endif
