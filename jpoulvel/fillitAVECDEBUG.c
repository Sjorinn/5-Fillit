/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:33:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:25 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		check_tetri(char *str)
{
	int		p;
	int		h;
	int		r;

	ft_putstr("ENTREE DANS CHECK TETRI");
	p = 0;
	h = 0;
	r = 0;
	if (!(str[4] == '\n' && str[9] == '\n' && str[14] == '\n' &&
				str[19] == '\n'))
		return (0);
	ft_putstr("\nOK SAUT LIGNE");
	while (str[p + h + r] == '.' || str[p + h + r] == '#' ||
			(str[p + h + r] == '\n'  && ((((p + h + r) - 4) % 5) == 0)))
	{
		if (str[p + h + r] == '.')
			p++;
		if (str[p + h + r] == '#')
			h++;
		if (str[p + h + r] == '\n' && ((((p + h + r) - 4) % 5) == 0))
			r++;
	}
	ft_putstr("\nnb_hashtag : ");
	ft_putnbr(h);
	ft_putstr("\nnb_points : ");
	ft_putnbr(p);
	ft_putstr("\nnb_returns : ");
	ft_putnbr(r);
	if (!(h == 4 && r == 4 && p == 12 ))
		return (0);
	ft_putstr("\nOK TETRI");
	return (1);
}

char		 **make_tetri(char *buf, int i)
{
	static char	**tab = NULL;

	ft_putstr("\nENTREE DANS MAKE TETRI");
	if (tab == NULL)
	{
		ft_putstr("\nMALLOC TAB");
		if (!(tab = (char**)malloc(sizeof(char*) * 27)))
			return (NULL);
	}
	if (!(tab[i] = ft_strnew(21)))
		return (NULL);
	buf[BUFF_SIZE - 1] = '\0';
	ft_strcpy(tab[i], buf);
	ft_putstr("\nTAB[i] : ");
	ft_putstr(tab[i]);
	if (!(check_tetri(tab[i])))
		return (NULL);
	ft_putstr("\ni : ");
	ft_putnbr(i);
	ft_putstr("\ntab[i] : ");
	ft_putstr(tab[i]);
	return (tab);
}

int			main()
{
	int		fd;
	int		nb_tetri;
	char	buf[BUFF_SIZE];
	int		ret;

	nb_tetri = 0;
	ft_putstr("\nok");
	if ((fd = open("Tetris.txt", O_RDONLY)) <= 0)
		return (0);
	ft_putnbr(fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putnbr(ret);
		ft_putstr("\nBUF LU : ");
		ft_putstr(buf);
		if (!(make_tetri(buf, nb_tetri)))
			return (0);
		nb_tetri++;
	}
	if (nb_tetri > 26)
		return (0);
	ft_putstr("\nnb_tetri : ");
	ft_putnbr(nb_tetri);
	return(nb_tetri);
}
