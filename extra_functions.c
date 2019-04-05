/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:41:01 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/20 09:05:49 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char			**make_tab(int tab_size)
{
	int		i;
	int		j;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (tab_size + 1))))
		return (NULL);
	i = -1;
	while (++i <= tab_size)
		if (!(tab[i] = (char *)malloc(sizeof(char) * (tab_size + 1))))
			return (NULL);
	i = -1;
	while (++i < tab_size)
	{
		j = -1;
		while (++j < tab_size)
			tab[i][j] = '.';
		tab[i][j] = '\0';
	}
	free(tab[i]);
	tab[i] = NULL;
	return (tab);
}

void			free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void			ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

t_tetri_list	*list_alloc(int list_len)
{
	int				i;
	t_tetri_list	*elem;
	t_tetri_list	*begin_list;
	t_tetri_list	*prev_elem;

	if (!(elem = (t_tetri_list *)malloc(sizeof(t_tetri_list))))
		return (NULL);
	begin_list = elem;
	i = -1;
	while (++i < list_len)
	{
		elem->mv_x = 0;
		elem->mv_y = 0;
		elem->letter = 0;
		(i >= 1) ? elem->prev = prev_elem : 0;
		prev_elem = elem;
		if (!(elem->next = (t_tetri_list *)malloc(sizeof(t_tetri_list))))
			return (NULL);
		elem = elem->next;
	}
	elem = begin_list;
	return (elem);
}

void			free_list(t_tetri_list *list)
{
	t_tetri_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}
