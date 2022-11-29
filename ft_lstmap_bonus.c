/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:42:03 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/29 19:10:47 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*ptr;

	result = NULL;
	while (lst != NULL)
	{
		ptr = f(lst->content);
		tmp = ft_lstnew(ptr);
		if (tmp == NULL)
		{
			ft_lstclear(&result, del);
			del(ptr);
			break ;
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
