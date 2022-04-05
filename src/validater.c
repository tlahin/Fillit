/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:13:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/04/01 13:14:09 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_blocks(char *buf)
{
	int	i;
	int	empty;
	int	hash;

	i = 0;
	empty = 0;
	hash = 0;
	while (i < 20)
	{
		if (buf[i] == '.')
			empty++;
		else if (buf[i] == '#')
			hash++;
		i++;
	}
	return (hash == 4 && empty == 12);
}

static int	validate_shape(char *buff)
{
	int	connection;
	int	i;

	connection = 0;
	i = 0;
	while (i < 19)
	{
		if (buff[i] == '#' && i > 4 && buff[i - 5] == '#')
			connection++;
		if (buff[i] == '#' && i % 5 != 0 && buff[i - 1] == '#')
			connection++;
		if (buff[i] == '#' && i % 5 != 3 && buff[i + 1] == '#')
			connection++;
		if (buff[i] == '#' && i < 14 && buff[i + 5] == '#')
			connection++;
		i++;
	}
	return (connection == 6 || connection == 8);
}

static int	validate_map(char *buff)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (buff[i] != '.' && buff[i] != '#')
			return (0);
		i++;
	}
	if (buff[20] != '\n' && buff [20] != '\0')
		return (0);
	return (1);
}

int	validater(char *buf)
{
	int	j;

	j = 0;
	j += validate_blocks(buf);
	j += validate_shape(buf);
	j += validate_map(buf);
	if (j != 3)
		return (0);
	return (1);
}
