/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:57:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/03/23 14:57:56 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	write_board(char **board, int board_size)
{
	int	i;

	i = 0;
	while (i < board_size)
	{
		write(1, board[i], board_size);
		write(1, "\n", 1);
		i++;
	}
}

static void	add_piece(t_tetri **tetris, char **board, int i)
{
	t_longlong	a;
	int			j;
	int			k;

	a = 1;
	j = 0;
	k = 0;
	while (j < tetris[i]->height)
	{
		while (k < tetris[i]->width)
		{
			if (((a << (16 * j)) << (15 - k)) & tetris[i]->bitf)
				board[tetris[i]->y + j][tetris[i]->x + k] = tetris[i]->name;
			k++;
		}
		j++;
		k = 0;
	}
}

static char	**new_board(int board_size)
{
	char	**board;
	int		i;

	i = 0;
	board = (char **)malloc(sizeof(board) * board_size);
	while (i < board_size)
	{
		board[i] = (char *)malloc(board_size + 1);
		if (!(board[i]))
		{
			while (--i >= 0)
				free(board[i]);
			free(board);
			return (NULL);
		}
		ft_memset(board[i], '.', board_size);
		i++;
	}
	return (board);
}

void	writer(t_tetri **tetris, int board_size, int pieces)
{
	char	**board;
	int		i;

	board = new_board(board_size);
	if (board == NULL)
	{
		while (--pieces >= 0)
			free(tetris[pieces]);
		error_message();
	}
	i = 0;
	while (i < pieces)
	{
		add_piece(tetris, board, i);
		i++;
	}
	write_board(board, board_size);
	while (--board_size >= 0)
		free(board[board_size]);
	free(board);
	while (--i >= 0)
		free(tetris[i]);
}
