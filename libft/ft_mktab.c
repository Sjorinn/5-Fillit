/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:22:16 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/18 12:07:23 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_mktab(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		words;

	i = 0;
	j = 0;
	words = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	words = -1;
	while (s[i + j])
	{
		while (s[i + j] == c)
			i++;
		if (s[i + j] != '\0')
			words++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j != 0)
			tab[words] = ft_strsub(s, i, j);
		i = i + j;
		j = 0;
	}
	tab[words + 1] = 0;
	return (tab);
}
