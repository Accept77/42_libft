/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:19:15 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/30 16:10:23 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
				j++;
	return (j);
}

static void	ft_free(char **re, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(re[i]);
		i++;
	}
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_fill(char const *s, char c, char **re)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = ft_word(s, c, i);
			re[index] = (char *)malloc(sizeof(char) * (j + 1));
			if (!re[index])
			{
				ft_free(re, index);
				return (1);
			}
			ft_strlcpy(re[index], s + i, j + 1);
			i += j;
			index++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	size_t	words;
	size_t	flag;

	words = ft_word_count(s, c);
	re = (char **)malloc(sizeof(char *) * (words + 1));
	if (!re)
		return (NULL);
	flag = ft_fill(s, c, re);
	if (flag == 1)
	{
		free(re);
		return (NULL);
	}
	re[words] = NULL;
	return (re);
}
