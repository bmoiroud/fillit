/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:41:48 by bmoiroud          #+#    #+#             */
/*   Updated: 2016/12/03 14:27:13 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			**tetriminos;
	char			letter;
	int				placed;
	int				len;
	int				width;
	struct s_list	*next;
}					t_list;

typedef struct		s_map
{
	char			**map;
	int				size;
}					t_map;

void				ft_putstr(char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_checkblock(char block[BUFF_SIZE], int i, int nb);
void				ft_copyblock(t_list *lst, char block[21], int i, int j);
void				ft_cleanblock(t_list *lst, char block[21], int i, int j);
void				ft_checkfile(char *str, t_list *lst, int i);
void				ft_lstdel(t_list *lst);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void);
int					ft_sqrt(int nb);
void				ft_error(int error, t_list *lst, t_map *map);
void				ft_place(t_map *map, t_list *lst, int x, int y);
int					ft_landing(t_map *map, t_list *lst, int x, int y);
void				ft_remove(t_map *map, t_list *lst, int x, int y);
int					ft_checkplacement(t_list *lst);
t_map				*ft_createmap(t_map *map, t_list *lst);
void				ft_print(t_map *map);
t_map				*ft_mapinit(t_map *map);
t_map				*ft_reallocmap(int size);
void				ft_freeall(t_map *map, t_list *lst);
int					ft_countlines(char *str);

#endif
