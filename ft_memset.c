/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:10:45 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/17 14:32:00 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*tmp;

	count = 0;
	tmp = (unsigned char *)b;
	while (count < len)
	{
		tmp[count] = (unsigned char)c;
		count++;
	}
	return (tmp);
}
