/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:27:59 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/03/23 14:44:03 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef unsigned long long	t_longlong;
typedef unsigned short		t_short;

typedef struct s_piece
{
	t_longlong	bitf;
	int			width;
	int			height;
	int			x;
	int			y;
	char		name;
}				t_tetri;

void			error_message(void);
int				reader(int fd, t_tetri **tetris);
int				solver(t_tetri **tetris, int pieces);
void			writer(t_tetri **tetris, int board_size, int pieces);
int				validater(char *buf);

#endif
