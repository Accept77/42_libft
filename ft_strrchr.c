/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:20:48 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/23 16:11:16 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = 0;
	if (c >= 256)
		c %= 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		tmp = ((char *)&s[i]);
	return (tmp);
}
