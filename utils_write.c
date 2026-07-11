/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:30:01 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/11 19:56:34 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

void	ft_put_float_percent_fd(float n, int fd)
{
	int	n_int;
	int	integer;
	int	decimal;

	n_int = (int) (n * 10000.0f + 0.5f);
	integer = n_int / 100;
	decimal = n_int % 100;
	ft_putnbr_fd(integer, fd);
	ft_putchar_fd('.', fd);
	if (decimal < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(decimal, fd);
	ft_putchar_fd('%', fd);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}