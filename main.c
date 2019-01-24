/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:33:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/22 15:27:21 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		nb_tetri;
	char	**tetri;
	char	**tetri2;
	char	buf[BUFF_SIZE];
	int		ret;

	i = 0;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) <= 0)
	{
		ft_putstr("error");
		return (0);
	}
	nb_tetri = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(tetri = check_tetri(buf, nb_tetri)))
		{
			ft_putstr("error");
			return (0);
		}
		nb_tetri++;
	}
	if (nb_tetri > 26)
	{
		ft_putstr("error");
		return (0);
	}
	ft_putnbr(nb_tetri);
	ft_putchar('\n');
	if (!(tetri2 = placetetri(tetri, nb_tetri)))
		return (-1);
	while (i < 4)
	{
		ft_putstr(tetri2[i]);
		ft_putstr("OK\n");
		i++;
	}
	return(1);
}
