/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:33 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/23 14:24:14 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 == 0 && src1 == 0 && len > 0)
		return (dest1);
	if (dest1 < src1)
	{
		count = -1;
		while (++count < len)
			dest1[count] = src1[count];
	}
	else
	{
		count = len;
		while (count)
		{
			dest1[count - 1] = src1[count - 1];
			count--;
		}
	}
	return (dest1);
}
