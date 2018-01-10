/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:15 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 17:53:55 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_resolution(t_map *map, t_list *lst, int x, int y)
{
	if (lst == NULL || ft_checkplacement(lst) == 0)
		return (ft_checkplacement(lst));
	if (x == map->size)
		return (ft_resolution(map, lst, 0, y + 1));
	if (y >= map->size)
		return (-1);
	if (ft_landing(map, lst, x, y) == 1)
		return (ft_resolution(map, lst, x + 1, y));
	ft_place(map, lst, x, y);
	if ((ft_resolution(map, lst->next, 0, 0)) == -1)
	{
		ft_remove(map, lst, x, y);
		return (ft_resolution(map, lst, x + 1, y));
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*tetriminos;
	t_map	*map;

	if ((map = (t_map *)malloc(sizeof(t_map *))) == NULL)
		ft_error(2, NULL, map);
	if (ac != 2)
		ft_error(1, NULL, map);
	if ((tetriminos = ft_lstnew()) == NULL)
		ft_error(2, tetriminos, map);
	ft_checkfile(av[1], tetriminos, 0);
	ft_createmap(map, tetriminos);
	ft_mapinit(map);
	while (ft_resolution(map, tetriminos, 0, 0))
		map = ft_reallocmap(map->size + 1);
	ft_print(map);
	ft_freeall(map, tetriminos);
	return (0);
}
