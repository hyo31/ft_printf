/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:37:15 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 14:54:48 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	rtn;
	int	t;

	i = skip_space(str, 0);
	n = 1;
	rtn = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	t = i;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		rtn = rtn * 10;
		rtn = rtn + (str[i] - '0');
		i++;
		if (i >= 26)
			return ((t - 1) * n);
	}
	return (rtn * n);
}
