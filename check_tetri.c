/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:53:11 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/20 09:05:43 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int				check_connex(char tetri[21])
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < 21)
	{
		if (tetri[i] == '#')
		{
			((i + 1 < 21) && (tetri[i + 1] == '#')) ? count++ : count + 0;
			((i - 1 >= 0) && (tetri[i - 1] == '#')) ? count++ : count + 0;
			((i + 5 < 21) && (tetri[i + 5] == '#')) ? count++ : count + 0;
			((i - 5 >= 0) && (tetri[i - 5] == '#')) ? count++ : count + 0;
		}
		i++;
	}
	if (count < 6)
		return (0);
	return (1);
}

int				check_file(char *str)
{
	int			p;
	int			h;
	int			r;

	p = 0;
	h = 0;
	r = 0;
	if (!(str[4] == '\n' && str[9] == '\n' && str[14] == '\n' &&
				str[19] == '\n'))
		return (0);
	while (str[p + h + r] == '.' || str[p + h + r] == '#' ||
			(str[p + h + r] == '\n' && ((((p + h + r) - 4) % 5) == 0)))
	{
		if (str[p + h + r] == '.')
			p++;
		if (str[p + h + r] == '#')
			h++;
		if (str[p + h + r] == '\n' && ((((p + h + r) - 4) % 5) == 0))
			r++;
	}
	if (!(h == 4 && r == 4 && p == 12))
		return (0);
	return (1);
}

char			**check(char *buf, int i, int j)
{
	static int	nb = -1;
	static char	**tab = NULL;

	if (tab == NULL)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * 27)))
			return (NULL);
	}
	if (nb == -1)
	{
		while (++nb < 26)
		{
			if (!(tab[nb] = ft_strnew(21)))
				return (NULL);
		}
		tab[nb] = NULL;
	}
	buf[BUFF_SIZE - 1] = '\0';
	if (!(check_connex(buf)) || !(check_file(buf)) || i >= 26 || j < 20)
	{
		free_tab(tab);
		return (NULL);
	}
	ft_strcpy(tab[i], buf);
	return (tab);
}
