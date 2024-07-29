/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:18:44 by relvan            #+#    #+#             */
/*   Updated: 2023/07/06 20:18:46 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*all;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	all = (char *)malloc(len * sizeof(char));
	if (all == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		all[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		all[i + j] = s2[j];
		j++;
	}
	all[i + j] = '\0';
	return (all);
}
