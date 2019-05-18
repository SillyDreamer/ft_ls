/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:45:11 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 18:47:16 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_FT_H
# define CONV_FT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define PP 9223372036854775807

char			*ft_itoa(int n);
char			*ft_ftoa(double num, int acc);
int				ft_atoi(const char *str);

#endif
