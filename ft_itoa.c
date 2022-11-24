/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:16:02 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/24 16:00:31 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_min(int n, int *flag)
{
	if (0 > n && n > -2147483648)
	{
		n *= -1;
		*flag = 1;
		return (n);
	}
	else if (n == -2147483648)
	{
		n++;
		n *= -1;
		*flag = 2;
		return (n);
	}
	else
		return (n);
}

static int	ft_len(int tmp)
{
	int	count;

	count = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		count++;
	}
	return (count);
}

static void	ft_num_fill(int tmp, int flag, char *result, int len)
{
	int	end;

	end = len - 1;
	while (tmp > 0)
	{
		result[len - 1] = (tmp % 10) + '0';
		tmp = tmp / 10;
		len--;
	}
	if (flag == 1)
		result[0] = '-';
	else if (flag == 2)
	{
		result[0] = '-';
		result[end]++;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		flag;
	int		tmp;

	len = 0;
	flag = 0;
	tmp = ft_is_min(n, &flag);
	len = ft_len(tmp);
	if (flag == 1 || flag == 2 || tmp == 0)
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memset(result, '0', len);
	result[len] = '\0';
	ft_num_fill(tmp, flag, result, len);
	return (result);
}
