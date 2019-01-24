/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placetetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:50:34 by pchambon          #+#    #+#             */
/*   Updated: 2019/01/24 15:09:17 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**maketab(int tabsize)
{
	int				ligne;
	char			**tab;

	ligne = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * tabsize + 1)))
		return (NULL);
	while (ligne < tabsize)
	{
		if (!(tab[ligne] = (char *)malloc((tabsize + 1) * sizeof(char))))
			return (NULL);
		tab[ligne][tabsize + 1] = '\0';
		ligne++;
	}
	ligne = 0;
	while (ligne < tabsize)
	{
		ft_memset(tab[ligne], '.', tabsize);
		ligne++;
	}
	ft_putstr("MAKETAB : OK\n");
	return (tab);
}

char	**placetab(char **tab, int nb_tetri, int stock[nb_tetri][8])
{
	int		i;
	int		j;

	i = 0;
	while (++j < 8)
	{
		if(tab[stock[i][j]][stock[i][++j]] != '.')
			return(-1);
	}
	while (stock[j])
	ft_putstr("PLACETAB : OK\n");
	return (tab);
}

char	**placetetri_ext(char **tab, char **tetris, int nb_tetri)
{
	int i;
	int j;
	int k;
	int l;
	int stock[nb_tetri][8];

	i = 0;
	j = 0;
	while (i < nb_tetri)
	{
		k = -2;
		l = -2;
		dprintf(1, "Tetrimino %i\n", (i + 1));
		dprintf(1, "%s", tetris[i]);
		while (tetris[i][j])
		{
			if (tetris[i][j] == '#')
			{
				ft_putnbr(stock[i][0 + (k += 2)] = j / 5);
				ft_putchar('|');
				ft_putnbr(stock[i][1 + (l += 2)] = j % 5);
				ft_putchar('\n');
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_putstr("PLACETETRI_EXT : OK\n");
	return (placetab(tab, nb_tetri, stock));
}

char	**placetetri(char **tetris, int nb_tetri)
{
	int i;

	i = 0;
	while ((i * i) < (nb_tetri * 4))
		i++;
	ft_putstr("PLACETETRI : OK\n");
	return (placetetri_ext(maketab(i), tetris, nb_tetri));
}
