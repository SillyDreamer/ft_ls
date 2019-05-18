/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:17:26 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:46:01 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

static int		ft_count_word(char const *str, char c)
{
	int count;
	int	flag;

	if (!str)
		return (0);
	count = 0;
	while (*str == c)
		str++;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static int		ft_word_size(char const *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (*str != c && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static char		**ft_initial(int *i, int *j, int count, char ***words)
{
	*i = 0;
	*j = 0;
	*words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (*words);
}

static char		*ft_push_str(char const **s, char **word, int *i, char c)
{
	while (**s == c && **s != '\0')
		(*s)++;
	while (**s != c && **s != '\0')
		(*word)[(*i)++] = *(*s)++;
	(*word)[*i] = '\0';
	return (*word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*word;
	int		count;
	int		i;
	int		j;

	count = ft_count_word(s, c);
	if (!s || ft_initial(&i, &j, count, &words) == NULL)
		return (NULL);
	while (j < count)
	{
		if (!(word = (char *)malloc(sizeof(char) * (ft_word_size(s, c) + 1))))
		{
			i = -1;
			while (words[++i] && j--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		word = ft_push_str(&s, &word, &i, c);
		words[j++] = word;
		i = 0;
	}
	words[count] = NULL;
	return (words);
}
