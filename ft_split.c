/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:19:15 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/28 13:27:23 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_free(char **result, size_t index)
{
	while (index >= 0)
	{
		free(result[index]);
		index--;
	}
	free(result);
	return (1);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	l;
	size_t	word;

	l = 0;
	word = 0;
	while (s[l])
	{
		if (s[l] != c && (s[l + 1] == c || s[l + 1] == '\0'))
			word++;
		l++;
	}
	return (word);
}

static void	ft_fill(char const *s, char c, char **result, size_t *flag)
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
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			result[index] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(result[index]))
				*flag = ft_free(result, index);
			ft_strlcpy(result[index], s + i, j + 1);
			i += j;
			index++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;
	size_t	flag;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	flag = 0;
	if (!result)
		return (NULL);
	result[words] = 0;
	ft_fill(s, c, result, &flag);
	if (flag == 1)
		return (NULL);
	return (result);
}
