/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:03:57 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/03/23 14:38:14 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** get_piece_edges gives us the edge indexes of the piece, both x and y
** Also, counts the width and height of the piece and inserts them
** [0] = left index, [1] = right index, [2] = top index, [3] = bottom index
*/

static void	get_piece_edges(char *buf, int *edges, t_tetri *new)
{
	int	j;

	j = 0;
	edges[0] = 3;
	edges[1] = 0;
	edges[2] = 3;
	edges[3] = 0;
	while (j <= 18)
	{
		if (buf[j] == '#')
		{
			if (j % 5 < edges[0])
				edges[0] = j % 5;
			if (j % 5 > edges[1])
				edges[1] = j % 5;
			if (j / 5 < edges[2])
				edges[2] = j / 5;
			if (j / 5 > edges[3])
				edges[3] = j / 5;
		}
		++j;
	}
	new->width = edges[1] - edges[0] + 1;
	new->height = edges[3] - edges[2] + 1;
}

static t_tetri	*make_tetri(char *buf, t_tetri **tetris, int current)
{
	t_tetri		*new;
	int			edges[4];
	int			i;
	t_longlong	l;

	l = 1;
	i = 0;
	new = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new)
	{
		while (--current >= 0)
			free(tetris[current]);
		return (NULL);
	}
	ft_bzero(new, sizeof(t_tetri));
	get_piece_edges(buf, edges, new);
	while (i < 19)
	{
		if (buf[i] == '#')
			new->bitf |= ((l << (16 * ((i / 5) - edges[2]))) \
				<< (15 - i % 5 + edges[0]));
		++i;
	}
	return (new);
}

int	reader(int fd, t_tetri **tetris)
{
	char	buf[21];
	int		b_val;
	int		i;
	int		j;

	i = 0;
	ft_bzero(buf, sizeof(buf));
	b_val = read(fd, buf, 21);
	while (b_val >= 20 && i < 26)
	{
		if (b_val == 20)
			buf[20] = '\0';
		j = validater(buf);
		if (!j)
			return (-1);
		tetris[i] = make_tetri(buf, tetris, i);
		if (tetris[i] == NULL)
			return (-1);
		tetris[i]->name = 'A' + i;
		i++;
		b_val = read(fd, buf, 21);
	}
	if (b_val != 0 || buf[20] != '\0' || (b_val == 0 && i == 0))
		return (-1);
	return (i);
}
