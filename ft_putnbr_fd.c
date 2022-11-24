/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:45:38 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/22 16:47:40 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	numprint(int n, int fd, int flag)
{
	char	p[11];
	int		count;

	count = 0;
	while (n != 0)
	{
		p[count] = n % 10 + '0';
		n /= 10;
		count++;
	}
	p[count] = '\0';
	--count;
	if (flag == 1)
		p[0]++;
	while (count >= 0)
	{
		write(fd, &p[count], 1);
		count--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	flag;

	flag = 0;
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
	{
		flag++;
		n++;
		n *= -1;
		write(fd, "-", 1);
	}
	else if (0 > n && n > -2147483648)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	numprint(n, fd, flag);
}
