/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:07:02 by jinsyang          #+#    #+#             */
/*   Updated: 2022/11/29 12:43:27 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_new;

	node_new = (t_list *)malloc(sizeof(t_list));
	if (!node_new)
		return (NULL);
	node_new->content = content;
	node_new->next = NULL;
	return (node_new);
}
