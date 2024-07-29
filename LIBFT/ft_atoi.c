/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:15:08 by relvan            #+#    #+#             */
/*   Updated: 2023/07/19 15:52:49 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		say;
	long	nb;

	say = 0;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			say++;
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	if (say == 1)
		nb = -nb;
	return ((int)nb);
}
