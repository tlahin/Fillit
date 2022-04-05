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

static void	min_maxer(char *buf, int *mx)
{
	int	j;

	j = 0;
	mx[0] = 3;
	mx[1] = 0;
	mx[2] = 3;
	mx[3] = 0;
	while (j <= 18)
	{
		if (buf[j] == '#')
		{
			if (j % 5 < mx[0])
				mx[0] = j % 5;
			if (j % 5 > mx[1])
				mx[1] = j % 5;
			if (j / 5 < mx[2])
				mx[2] = j / 5;
			if (j / 5 > mx[3])
				mx[3] = j / 5;
		}
		++j;
	}
}

static t_tetri	*make_tetri(char *buf)
{
	t_tetri		*new;
	int			mx[4];
	int			i;
	t_longlong	l;

	l = 1;
	i = 0;
	new = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_tetri));
	min_maxer(buf, mx);
	new->width = mx[1] - mx[0] + 1;
	new->height = mx[3] - mx[2] + 1;
	while (i < 19)
	{
		if (buf[i] == '#')
			new->bitf |= ((l << (16 * ((i / 5) - mx[2]))) \
				<< (15 - i % 5 + mx[0]));
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
		tetris[i] = make_tetri(buf);
		tetris[i]->name = 'A' + i;
		i++;
		b_val = read(fd, buf, 21);
	}
	if (b_val != 0 || buf[20] != '\0' || (b_val == 0 && i == 0))
		return (-1);
	return (i);
}
