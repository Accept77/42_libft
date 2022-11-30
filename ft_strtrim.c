/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:30:43 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/30 13:50:57 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	total_len;

	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	while (is_set(s1[end - 1], set))
		end--;
	total_len = end - start + 1;
	result = (char *)malloc(sizeof(char) * (total_len));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, total_len);
	return (result);
}
