/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:04:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/20 09:07:23 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct	s_place_list
{
	int					x;
	int					y;
	int					z;
	int					last_tetri;
}				t_place_list;

typedef	struct	s_tetri_list
{
	int					x[4];
	int					y[4];
	int					letter;
	int					mv_x;
	int					mv_y;
	struct s_tetri_list	*next;
	struct s_tetri_list *prev;
}				t_tetri_list;

int				int_str(const char *s, int fd);
int				int_free(void *obj);
int				main(int argc, char **argv);
int				main_ext(t_place_list *nb, char **tetri_str);
int				place_tetri(t_tetri_list *tetri, int *tab_size);
void			ft_print_tab(char **tab);
char			**check(char *buf, int i, int j);
int				check_file(char *str);
int				check_connex(char *tetri);
t_tetri_list	*block_coord(char **tab, int nb_tetri);
t_tetri_list	*shift_tetri(t_tetri_list *tetri);
t_tetri_list	*list_alloc(int list_len);
char			**make_tab(int tab_size);
void			free_list(t_tetri_list *list);
void			free_tab(char **tab);
int				backtrack(t_tetri_list *tetri, char ***tab, int *size);
int				backtrack_ext(t_tetri_list *tetri, char ***tab, int *size);
char			**check_n_place(t_tetri_list *pos, char **tab, int size);
int				move_tetri(t_tetri_list *tetri, int size);
char			**remove_tetri(int letter, char **tab);
#endif
