/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:24:15 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/02 18:19:57 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdel(t_list *lst)
{
	if (lst->next != NULL)
		ft_lstdel(lst->next);
	free(lst->tetriminos);
	lst->next = NULL;
	free(lst);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(void)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		new->tetriminos = NULL;
		new->next = NULL;
		new->letter = 'A';
		new->placed = 0;
		new->len = 0;
		new->width = 0;
	}
	return (new);
}
