/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:46:21 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/23 17:50:53 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	cc;

	i = 0;
	tmp = (unsigned char *)s;
	cc = (unsigned char)c;
	if (c >= 256)
		cc = c % 256;
	while (i < n)
	{
		if (tmp[i] == cc)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
