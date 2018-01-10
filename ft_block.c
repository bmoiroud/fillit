/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:31:21 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 14:25:26 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countlinks(char block[BUFF_SIZE], int i)
{
	int nb;

	nb = 0;
	if (i < BUFF_SIZE && block[i + 1] == '#')
		nb++;
	if (i > 0 && block[i - 1] == '#')
		nb++;
	if (i < BUFF_SIZE - 6 && block[i + 5] == '#')
		nb++;
	if (i > 4 && block[i - 5] == '#')
		nb++;
	return (nb);
}

void	ft_checkblock(char block[BUFF_SIZE], int i, int nb)
{
	int		n;
	int		nb2;

	nb2 = 0;
	n = 0;
	while (block[++i] && i < BUFF_SIZE - 1)
	{
		if (block[i] == '#')
		{
			n++;
			nb += ft_countlinks(block, i);
		}
		if ((block[i] != '.' && block[i] != '#') && (i + 1) % 5 != 0 && i < 21)
			ft_error(2, NULL, NULL);
		if (block[i] != '\n' && (i + 1) % 5 == 0)
			ft_error(2, NULL, NULL);
	}
	if ((nb != 6 && nb != 8) || n != 4)
		ft_error(2, NULL, NULL);
}

void	ft_copyblock(t_list *lst, char block[BUFF_SIZE], int i, int j)
{
	int n;

	n = 0;
	lst->len = (j - i) / 5 + 1;
	lst->width = (j - i) % 5 + 1;
	lst->tetriminos = (char **)malloc(sizeof(char *) * lst->len);
	n = 0;
	while (n < lst->len)
	{
		lst->tetriminos[n] = (char *)malloc(sizeof(char) * lst->width);
		n++;
	}
	if (lst->tetriminos == NULL)
		ft_error(2, lst, NULL);
	n = 0;
	block += i;
	while (n < lst->len)
	{
		ft_strncpy(lst->tetriminos[n], block, lst->width);
		block += 5;
		n++;
	}
}

void	ft_cleanblock(t_list *lst, char block[BUFF_SIZE], int i, int j)
{
	int n;

	n = 0;
	while (block[i] != '#')
		i++;
	if (block[i + 4] == '#' || block[i + 9] == '#')
		i--;
	if (block[i + 4] == '#')
		i--;
	j = i - 1;
	while (n != 4)
		n = ((block[++j] == '#') ? (n + 1) : n);
	if (block[j - 4] == '#')
		j++;
	if (block[j - 4] == '#')
		j++;
	ft_copyblock(lst, block, i, j);
}

void	ft_checkfile(char *str, t_list *lst, int i)
{
	int		file;
	int		nb;
	char	buff[BUFF_SIZE];
	t_list	*start;

	nb = 0;
	start = lst;
	if ((file = open(str, O_RDONLY)) == -1)
		ft_error(2, lst, NULL);
	while (read(file, buff, BUFF_SIZE))
	{
		nb += ft_countlines(buff);
		buff[BUFF_SIZE - 1] = '\0';
		ft_checkblock(buff, -1, 0);
		ft_cleanblock(lst, buff, 0, 0);
		lst->letter = 'A' + i;
		i++;
		ft_lstadd(&lst->next, ft_lstnew());
		lst = lst->next;
		ft_bzero(buff, BUFF_SIZE);
	}
	if ((nb - (i - 1)) % 4 != 0)
		ft_error(2, lst, NULL);
	close(file);
	lst = start;
}
