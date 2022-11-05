/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:12:06 by ahussein          #+#    #+#             */
/*   Updated: 2022/07/24 19:15:43 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint_len(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	long	nbr;
	char	*str;

	nbr = n;
	i = ft_uint_len(nbr);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	return (str);
}

int	ft_printu_number(unsigned int n)
{
	int		len;
	char	*digits;

	len = 0;
	if (n == 0)
	{
		len += ft_printchar('0');
		return (1);
	}
	else
	{
		digits = ft_uitoa(n);
		len += ft_printstr(digits);
		free(digits);
	}
	return (len);
}
