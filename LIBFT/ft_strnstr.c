/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:19:25 by relvan            #+#    #+#             */
/*   Updated: 2023/07/14 13:27:03 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = len;
	i = 0;
	if (needle[i] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && (i < l))
	{
		j = 0;
		while (haystack[i + j] != '\0' && needle[j] != '\0'
			&& haystack[i + j] == needle[j] && (i + j < l))
			j++;
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
