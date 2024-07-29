/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:17:17 by relvan            #+#    #+#             */
/*   Updated: 2023/07/14 13:10:19 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	n;

	n = 0;
	if (len <= 0 || (dest == src))
		return (dest);
	if (src < dest)
	{
		n = len;
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (n < len)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			n++;
		}
	}
	return (dest);
}
