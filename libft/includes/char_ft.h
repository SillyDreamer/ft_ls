/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:36:21 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/11 08:42:08 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_FT_H
# define CHAR_FT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(char c);

#endif
