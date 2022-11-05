/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:53:01 by ahussein          #+#    #+#             */
/*   Updated: 2022/07/24 18:53:02 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char condition)
{
	if (num >= 16)
	{
		ft_puthex((num / 16), condition);
		ft_puthex((num % 16), condition);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
		{
			if (condition == 'x')
				ft_printchar((num - 10 + 'a'));
			else if (condition == 'X')
				ft_printchar((num - 10 + 'A'));
		}
	}
}

int	ft_printhex(unsigned int num, const char condition)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_puthex(num, condition);
	return (ft_hexlen(num));
}
