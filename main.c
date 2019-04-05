/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:33:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/26 12:43:43 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		int_str(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return (0);
}

int		int_free(void *obj)
{
	free(obj);
	return (0);
}

int		place_tetri(t_tetri_list *tetri, int *tab_size)
{
	static char		**tab;
	int				i;
	t_tetri_list	*tmp;

	tmp = tetri;
	i = 1;
	if (!(tab = make_tab(tab_size[0])))
		return (-1);
	while ((i = backtrack(tmp, &tab, tab_size)) > 0)
	{
		while (tmp->letter != i)
			tmp = tmp->next;
		while (tmp->next != NULL)
		{
			tmp->next->mv_x = 0;
			tmp->next->mv_y = 0;
			tmp = tmp->next;
		}
		while (tmp->letter != (i - 1))
			tmp = tmp->prev;
		remove_tetri(tmp->letter, tab);
		move_tetri(tmp, tab_size[0]);
	}
	return (0);
}

int		main_ext(t_place_list *nb, char **tetri_str)
{
	t_tetri_list		*tetri;
	int					square_size[1];

	if (nb->z <= 0 && nb->x == 0)
		return (int_str("error\n", 1));
	if (nb->last_tetri != 20)
	{
		free_tab(tetri_str);
		return (int_str("error\n", 1));
	}
	tetri = shift_tetri(block_coord(tetri_str, nb->x));
	free_tab(tetri_str);
	square_size[0] = 1;
	while ((square_size[0] * square_size[0]) < (nb->x * 4))
		square_size[0]++;
	if (tetri->next && !tetri->next->next && ((tetri->x[3] == 3 &&
					tetri->next->y[3] == 3)
		|| (tetri->y[3] == 3 && tetri->next->x[3] == 3)))
		square_size[0]++;
	if (place_tetri(tetri, square_size) == -1)
		ft_putstr_fd("error\n", 1);
	free_list(tetri);
	return (0);
}

int		main(int argc, char **argv)
{
	t_place_list	*nb;
	static char		**tetri = NULL;
	char			buf[BUFF_SIZE];

	if (argc != 2)
		return (int_str("usage: ./fillit target_file\n", 2));
	if (!(nb = (t_place_list *)malloc(sizeof(t_place_list))))
		return (-1);
	if ((nb->y = open(argv[1], O_RDONLY | O_NOFOLLOW)) <= 0)
		return (int_str("error\n", 1) + int_free(nb));
	nb->x = 0;
	while ((nb->z = read(nb->y, buf, BUFF_SIZE)) > 0)
	{
		nb->last_tetri = nb->z;
		if (!(tetri = check(buf, nb->x, nb->z)))
			return (int_str("error\n", 1) + int_free(nb));
		nb->x++;
	}
	main_ext(nb, tetri);
	free(nb);
	return (0);
}
