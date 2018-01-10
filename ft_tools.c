/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:29:30 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 17:51:19 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < nb)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

int		ft_countlines(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (i < BUFF_SIZE)
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

void	ft_freeall(t_map *map, t_list *lst)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	ft_lstdel(lst);
	map = NULL;
	lst = NULL;
}

void	ft_error(int error, t_list *lst, t_map *map)
{
	if (error == 1)
		ft_putstr("usage: ./fillit input_file\n");
	else if (error == 2)
		ft_putstr("error\n");
	if (map != NULL)
	{
		free(map);
		map = NULL;
	}
	if (lst != NULL)
	{
		ft_lstdel(lst);
		lst = NULL;
	}
	exit(EXIT_FAILURE);
}
