/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:34:04 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/03/23 14:42:04 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check(t_tetri *tetri, t_short *board)
{
	int	result;

	result = (!((tetri->bitf >> tetri->x) & *(t_longlong *)(board + tetri->y)));
	return (result);
}

static void	add_remove(t_longlong bitf, int x, int y, t_short *board)
{
	*(t_longlong *)(board + y) ^= bitf >> x;
}

static int	solve_board(t_tetri **tetris, t_short *board, int *arr, int i)
{
	while ((tetris[i])->y + tetris[i]->height <= arr[0])
	{
		while ((tetris[i])->x + tetris[i]->width <= arr[0])
		{
			if (check(tetris[i], board))
			{
				add_remove(tetris[i]->bitf, tetris[i]->x, tetris[i]->y, board);
				if (i == arr[1] - 1)
					return (arr[0]);
				else
				{
					if (solve_board(tetris, board, arr, i + 1) == arr[0])
						return (arr[0]);
				}
				add_remove(tetris[i]->bitf, tetris[i]->x, tetris[i]->y, board);
			}
			++tetris[i]->x;
		}
		++tetris[i]->y;
		tetris[i]->x = 0;
	}
	tetris[i]->y = 0;
	return (-1);
}

int	solver(t_tetri **tetris, int pieces)
{
	t_short	board[16];
	int		b_size;
	int		arr[2];

	(void)tetris;
	b_size = 0;
	ft_bzero(board, sizeof(board));
	while (b_size * b_size < pieces * 4)
		b_size++;
	arr[0] = b_size;
	arr[1] = pieces;
	while (solve_board(tetris, board, arr, 0) == -1 && arr[0] <= 16)
	{
		ft_bzero(board, sizeof(board));
		arr[0]++;
	}
	b_size = arr[0];
	if (b_size == -1)
		error_message();
	return (b_size);
}
