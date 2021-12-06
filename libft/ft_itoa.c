/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:25:00 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 14:58:19 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*make_str(char *str, int n, int i)
{
	int	j;

	j = 0;
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else
		n = n * -1;
	while (n != 0)
	{
		str[i - j] = (-(n % 10) + '0');
		n /= 10;
		j++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = n;
	if (n <= 0)
		i++;
	while (count != 0)
	{
		i++;
		count /= 10;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	make_str(str, n, i - 1);
	str[i] = '\0';
	return (str);
}
