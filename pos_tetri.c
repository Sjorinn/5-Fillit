/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:58:48 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/20 09:06:00 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

t_tetri_list	*shift_tetri(t_tetri_list *tetri)
{
	int					x;
	int					y;
	int					z;
	t_tetri_list		*begin_list;

	begin_list = tetri;
	while (tetri)
	{
		z = -1;
		x = 4;
		y = 4;
		while (++z < 4)
		{
			(tetri->x[z] < x) ? x = tetri->x[z] : 0;
			(tetri->y[z] < y) ? y = tetri->y[z] : 0;
		}
		z = -1;
		while (++z < 4)
		{
			tetri->x[z] = tetri->x[z] - x;
			tetri->y[z] = tetri->y[z] - y;
		}
		tetri = tetri->next;
	}
	return (begin_list);
}

t_tetri_list	*block_coord(char **tab, int nb_tetri)
{
	int				x;
	int				y;
	int				z;
	t_tetri_list	*tetri;
	t_tetri_list	*begin_list;

	tetri = list_alloc(nb_tetri);
	x = -1;
	while (++x < nb_tetri)
	{
		y = -1;
		z = 0;
		x != 0 ? tetri = tetri->next : 0;
		tetri->letter = 'A' + x;
		while (tab[x][++y])
			if (tab[x][y] == '#')
			{
				tetri->x[z] = y / 5;
				tetri->y[z++] = y % 5;
			}
		x == 0 ? begin_list = tetri : 0;
	}
	free(tetri->next);
	tetri->next = NULL;
	return (begin_list);
}
