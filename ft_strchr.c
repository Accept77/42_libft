/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:47:32 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/23 16:01:01 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c >= 256)
		c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return (((char *)&s[i]));
		i++;
	}
	if (s[i] == c)
		return (((char *)&s[i]));
	return (NULL);
}
