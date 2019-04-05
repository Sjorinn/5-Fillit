/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:43:19 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/20 09:06:04 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int				move_tetri(t_tetri_list *tetri, int size)
{
	if (tetri->mv_x == size - 1 && tetri->mv_y == size - 1)
		return (1);
	if (tetri->mv_y < size - 1)
	{
		tetri->mv_y++;
	}
	else if (tetri->mv_y == size - 1 && tetri->mv_x < size - 1)
	{
		tetri->mv_x++;
		tetri->mv_y = 0;
	}
	return (1);
}

char			**remove_tetri(int letter, char **tab)
{
	int			i;
	int			j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			(tab[i][j] == letter) ? tab[i][j] = '.' : 0;
	}
	return (tab);
}

char			**check_n_place(t_tetri_list *pos, char **tab, int size)
{
	if ((pos->x[0] + pos->mv_x) < size && (pos->y[0] + pos->mv_y) < size &&
			(pos->x[1] + pos->mv_x) < size && (pos->y[1] + pos->mv_y) < size &&
			(pos->x[2] + pos->mv_x) < size && (pos->y[2] + pos->mv_y) < size &&
			(pos->x[3] + pos->mv_x) < size && (pos->y[3] + pos->mv_y) < size)
	{
		if ((tab[pos->x[0] + pos->mv_x][pos->y[0] + pos->mv_y] == '.') &&
				(tab[pos->x[1] + pos->mv_x][pos->y[1] + pos->mv_y] == '.') &&
				(tab[pos->x[2] + pos->mv_x][pos->y[2] + pos->mv_y] == '.') &&
				(tab[pos->x[3] + pos->mv_x][pos->y[3] + pos->mv_y] == '.'))
		{
			tab[pos->x[0] + pos->mv_x][pos->y[0] + pos->mv_y] = pos->letter;
			tab[pos->x[1] + pos->mv_x][pos->y[1] + pos->mv_y] = pos->letter;
			tab[pos->x[2] + pos->mv_x][pos->y[2] + pos->mv_y] = pos->letter;
			tab[pos->x[3] + pos->mv_x][pos->y[3] + pos->mv_y] = pos->letter;
			return (tab);
		}
	}
	return (NULL);
}

int				backtrack_ext(t_tetri_list *tetri, char ***tab, int *size)
{
	if ((tetri->mv_x == size[0] - 1) && (tetri->mv_y == size[0] - 1))
	{
		tetri->mv_x = 0;
		tetri->mv_y = 0;
		if (tetri->letter == 'A')
		{
			free_tab(*tab);
			if (!(*tab = make_tab(++size[0])))
				return (-1);
		}
		else
			return (tetri->letter);
	}
	else
		move_tetri(tetri, size[0]);
	return (-2);
}

int				backtrack(t_tetri_list *tetri, char ***tab, int *size)
{
	static int	i = 0;
	static int	tmp;

	if ((tetri == NULL) && (++i == 1))
	{
		ft_print_tab(*tab);
		free_tab(*tab);
		return (0);
	}
	if (check_n_place(tetri, *tab, size[0]) == NULL)
	{
		tmp = backtrack_ext(tetri, tab, size);
		if (tmp != -2)
			return (tmp);
	}
	else
		tetri = tetri->next;
	backtrack(tetri, tab, size);
	if (i == 1)
		return (0);
	return (tmp);
}
