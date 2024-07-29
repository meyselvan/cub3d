/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:38 by relvan            #+#    #+#             */
/*   Updated: 2023/07/16 19:03:03 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	if (x < 0)
		len++;
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

static char	*ft_putnbr(char *dest, int n, int index)
{
	static int	i;

	i = index;
	if (n == -2147483648)
	{
		dest[0] = '-';
		dest[1] = '2';
		ft_putnbr(dest, 147483648, 2);
	}
	else if (n < 0)
	{
		dest[0] = '-';
		ft_putnbr(dest, -n, 1);
	}
	else if (n > 9)
	{
		ft_putnbr(dest, n / 10, i);
		ft_putnbr(dest, n % 10, i + 1);
	}
	else
	{
		dest[i] = n + 48;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	length;
	int		i;

	i = 0;
	length = ft_intlen(n) + 1;
	number = (char *)malloc(length * sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n == 0)
		number[0] = 48;
	else
		number = ft_putnbr(number, n, i);
	number[length - 1] = '\0';
	return (number);
}
