/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:04:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/22 15:27:09 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>


int		main();
int		check_file(char *str);
char	**check_tetri(char *buf, int i);
int		check_connex(char *tetri);
char	**placetetri(char	**tetris, int nb_tetri);

#endif
