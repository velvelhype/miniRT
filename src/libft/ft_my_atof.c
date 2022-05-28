/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_atof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:37:34 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 21:51:03 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>

static void		read_sign(int *sign, size_t *i, char c);
static double	ft_pow(double x, int y);
static double	get_decimal(const char *nptr);
static bool		check_format(const char *nptr);

double	ft_my_atof(const char *nptr, bool *flag)
{
	size_t	i;
	int		sign;
	double	result;

	*flag = check_format(nptr);
	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	read_sign(&sign, &i, nptr[i]);
	while (ft_isdigit(nptr[i]))
	{
		result = 10 * result + (nptr[i] - '0');
		if (result > MY_DOUBLE_MAX)
			*flag = false;
		i++;
	}
	if (nptr[i] == '.')
		result += get_decimal(&nptr[i + 1]);
	return (result * sign);
}

static void	read_sign(int *sign, size_t *i, char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign *= -1;
		(*i)++;
	}
}

static double	ft_pow(double x, int y)
{
	if (y == 0)
		return (1);
	if (y > 0)
		return (x * ft_pow(x, y - 1));
	if (y < 0)
		return (1 / ft_pow(x, -y));
	return (0);
}

static double	get_decimal(const char *nptr)
{
	size_t	i;
	double	decimal;

	i = 0;
	decimal = 0;
	while (ft_isdigit(nptr[i]))
	{
		decimal += (nptr[i] - '0') / (ft_pow(10, i + 1));
		i++;
	}
	return (decimal);
}

static bool	check_format(const char *nptr)
{
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (false);
	if (nptr[i] == '0' && !(nptr[i + 1] == '.' || nptr[i + 1] == '\0'))
		return (false);
	while (ft_isdigit(nptr[i]))
		i++;
	if (nptr[i] == '.')
	{
		i++;
		if (!ft_isdigit(nptr[i]))
			return (false);
		i++;
		while (ft_isdigit(nptr[i]))
			i++;
	}
	if (nptr[i] != '\0')
		return (false);
	return (true);
}
