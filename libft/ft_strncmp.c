/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:29 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:15:32 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		result;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && \
	s2[index] != '\0' && index < n - 1)
		index++;
	result = (unsigned const char)s1[index] - (unsigned const char)s2[index];
	return (result);
}
