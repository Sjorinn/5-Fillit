/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainREADnCHECK.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:33:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/18 17:15:30 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		nb_tetri;
	char	buf[BUFF_SIZE];
	int		ret;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) <= 0)
	{
		ft_putstr("error");
		return (0);
	}
	nb_tetri = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(check_tetri(buf, nb_tetri)))
		{
			ft_putstr("error");
			return (0);
		}
		nb_tetri++;
	}
	if (nb_tetri > 26)
		return (0);
	ft_putnbr(nb_tetri);
	return(nb_tetri);
}
