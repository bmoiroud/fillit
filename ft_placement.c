/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:28:19 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 14:25:00 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place(t_map *map, t_list *lst, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < lst->len)
	{
		while (j < lst->width)
		{
			if (map->map[y + i][x + j] == '.' && lst->tetriminos[i][j] == '#')
				map->map[y + i][x + j] = lst->letter;
			j++;
		}
		j = 0;
		i++;
	}
	lst->placed = 1;
}

int		ft_landing(t_map *map, t_list *lst, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (x + lst->width >= map->size || y + lst->len >= map->size)
		return (1);
	while (i < lst->len)
	{
		while (j < lst->width)
		{
			if (map->map[y + i][x + j] != '.' && lst->tetriminos[i][j] == '#')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_remove(t_map *map, t_list *lst, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < lst->len)
	{
		while (j < lst->width)
		{
			if (map->map[y + i][x + j] == lst->letter)
				map->map[y + i][x + j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	lst->placed = 0;
}

int		ft_checkplacement(t_list *lst)
{
	int		i;
	int		j;
	t_list	*start;

	if (lst == NULL)
		return (0);
	start = lst;
	j = 0;
	i = 0;
	while (lst != NULL)
	{
		i += lst->placed;
		j++;
		lst = lst->next;
	}
	lst = start;
	if (j != i)
		return (1);
	return (0);
}
