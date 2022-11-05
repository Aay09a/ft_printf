/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:05:37 by ahussein          #+#    #+#             */
/*   Updated: 2022/08/02 17:05:04 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precisions(va_list args, const char condition)
{
	int	char_len;

	char_len = 0;
	if (condition == 'c')
		char_len += ft_printchar(va_arg(args, int));
	else if (condition == 's')
		char_len += ft_printstr(va_arg(args, char *));
	else if (condition == 'd' || condition == 'i')
		char_len += ft_printnumber(va_arg(args, int));
	else if (condition == 'x' || condition == 'X')
		char_len += ft_printhex(va_arg(args, unsigned int), condition);
	else if (condition == 'u')
		char_len += ft_printu_number(va_arg(args, unsigned int));
	else if (condition == 'p')
		char_len += ft_printptr(va_arg(args, unsigned long long));
	else if (condition == '%')
		char_len += ft_printpercent();
	return (char_len);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		char_len;
	va_list	args;

	i = 0;
	char_len = 0;
	if (string == NULL)
		return (-1);
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			char_len += ft_precisions(args, string[i + 1]);
			i++;
		}
		else
			char_len += ft_printchar(string[i]);
		i++;
	}
	va_end(args);
	return (char_len);
}

int	main(void)
{
	char	*p = "10";
	ft_printf("%p", p);
	printf("\n%p", p);
}
