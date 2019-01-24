/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placetetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:50:34 by pchambon          #+#    #+#             */
/*   Updated: 2019/01/22 16:38:00 by pchambon         ###   ########.fr       */
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
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < nb_tetri)
	{
		/*while (++j < 8)
		{
			ft_putstr("OK\n");
			tab[stock[i][j]][stock[i][j + 1]] == '.' ? k++ : k + 0;
			j++;
			if (k == 4)
			{
				j = -1;
				while (++j < 8)
				{
					tab[stock[i][j]][stock[i][j + 1]] = 'A' + i;
					j++;
				}
			}
		}*/
		//j = 0;
		//k = 0;
	}
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
