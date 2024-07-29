/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:19:39 by relvan            #+#    #+#             */
/*   Updated: 2023/07/19 15:52:41 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*str;

	i = 0;
	x = 0;
	j = ft_strlen(s1);
	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j--;
	while (s1[i] && ft_strchr(set, s1[j]) && j > i)
		j--;
	str = ft_substr(s1, i, (j - i) + 1);
	return (str);
}
