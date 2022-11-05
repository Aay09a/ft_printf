/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:29:53 by ahussein          #+#    #+#             */
/*   Updated: 2022/07/25 17:31:29 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printpercent(void);
int		ft_printhex(unsigned int num, const char condition);
int		ft_printnumber(int n);
int		ft_printu_number(unsigned int n);
int		ft_printptr(unsigned long long ptr);
int		ft_precisions(va_list args, const char condition);
int		ft_printf(const char *string, ...);
int		ft_hexlen(unsigned int num);
void	ft_putstr(char *str);
void	ft_puthex(unsigned int num, const char condition);
void	ft_putptr(uintptr_t num);
int		ft_ptrlen(uintptr_t num);
#endif
