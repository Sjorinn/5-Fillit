/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:53:11 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/22 15:13:34 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_connex(char *tetri)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			tetri[i + 1] == '#' ? count++ : count + 0;
			tetri[i - 1] == '#' ? count++ : count + 0;
			tetri[i + 5] == '#' ? count++ : count + 0;
			tetri[i - 5] == '#' ? count++ : count + 0;
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
			(str[p + h + r] == '\n'  && ((((p + h + r) - 4) % 5) == 0)))
	{
		if (str[p + h + r] == '.')
			p++;
		if (str[p + h + r] == '#')
			h++;
		if (str[p + h + r] == '\n' && ((((p + h + r) - 4) % 5) == 0))
			r++;
	}
	if (!(h == 4 && r == 4 && p == 12 ))
		return (0);
	return (1);
}

char			**check_tetri(char *buf, int i)
{
	static char	**tab = NULL;

	if (tab == NULL)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * i + 1)))
			return (NULL);
	}
	if (!(tab[i] = ft_strnew(21)))
		return (NULL);
	buf[BUFF_SIZE - 1] = '\0';
	ft_strcpy(tab[i], buf);
	if (!(check_file(tab[i])))
		return (NULL);
	if (!(check_connex(tab[i])))
			return (NULL);
	return (tab);
}
