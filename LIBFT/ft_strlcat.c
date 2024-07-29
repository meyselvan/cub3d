/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:18:50 by relvan            #+#    #+#             */
/*   Updated: 2023/07/06 20:34:20 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	duzun;
	unsigned int	suzun;

	i = 0;
	x = 0;
	while (dest[x] != '\0')
	{
		x++;
	}
	duzun = x;
	suzun = ft_strlen(src);
	if (size == 0 || size <= duzun)
		return (suzun + size);
	while (src [i] != '\0' && i < size - duzun - 1)
	{
		dest[x] = src[i];
		i++;
		x++;
	}
	dest[x] = '\0';
	return (duzun + suzun);
}
