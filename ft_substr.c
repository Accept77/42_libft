/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:13:30 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/24 12:13:47 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = '\0';
		return (sub);
	}
	if (len_s < len)
	{
		sub = (char *)malloc(sizeof(char) * (len_s + 1));
		len = len_s - start;
	}
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!(sub))
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
