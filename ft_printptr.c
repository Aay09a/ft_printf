/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:11:30 by ahussein          #+#    #+#             */
/*   Updated: 2022/07/24 19:16:02 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t num)
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

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr((num / 16));
		ft_putptr((num % 16));
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
			ft_printchar((num - 10 + 'a'));
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	char_len;

	char_len = 0;
	char_len += ft_printstr("0x");
	if (ptr == 0)
		char_len += ft_printchar('0');
	else
	{
		ft_putptr(ptr);
		char_len += ft_ptrlen(ptr);
	}
	return (char_len);
}
