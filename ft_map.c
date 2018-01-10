/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:27:06 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 14:27:06 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_createmap(t_map *map, t_list *lst)
{
	t_list	*start;
	int		i;

	map->size = 0;
	i = 0;
	start = lst;
	while (lst != NULL)
	{
		i += 4;
		lst = lst->next;
	}
	map->size = ft_sqrt(i);
	map->map = (char **)malloc(sizeof(char *) * map->size);
	i = 0;
	while (i < map->size)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->size);
		i++;
	}
	if (map->map == NULL)
		ft_error(2, lst, map);
	lst = start;
	return (map);
}

void	ft_print(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size - 1)
	{
		ft_putstr(map->map[i]);
		ft_putstr("\n");
		i++;
	}
}

t_map	*ft_mapinit(t_map *map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < map->size - 1)
	{
		while (j < map->size - 1)
		{
			map->map[i][j] = '.';
			j++;
		}
		map->map[i][j] = '\0';
		j = 0;
		i++;
	}
	return (map);
}

t_map	*ft_reallocmap(int size)
{
	t_map	*newmap;
	int		i;

	i = 0;
	newmap = malloc(sizeof(t_map));
	if ((newmap->map = malloc(size * sizeof(char **))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		if ((newmap->map[i] = malloc(size * sizeof(char *))) == NULL)
			return (NULL);
		i++;
	}
	newmap->size = size;
	ft_mapinit(newmap);
	return (newmap);
}
