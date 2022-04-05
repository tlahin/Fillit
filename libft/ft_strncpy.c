/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:07:36 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/23 14:16:49 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
