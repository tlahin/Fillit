/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:33:56 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/03/23 13:33:59 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_message(void)
{
	ft_putendl("error");
	sleep(10);
	exit(0);
}

int	main(int argc, char **argv)
{
	int			fd;
	const char	*file;
	t_tetri		*tetris[26];
	int			board_size;
	int			pieces;

	ft_bzero(tetris, sizeof(tetris));
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		exit(0);
	}
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (!(fd))
		error_message();
	pieces = reader(fd, tetris);
	if (pieces == -1)
		error_message();
	board_size = solver(tetris, pieces);
	writer(tetris, board_size, pieces);
	sleep(10);
	return (0);
}
