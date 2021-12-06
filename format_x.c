/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_x.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:22:56 by mgroen        #+#    #+#                 */
/*   Updated: 2021/05/11 14:32:26 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned long int num)
{
	int	i;

	i = 1;
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static int	add_char_x(int n, char **str, char c, struct s_flags flag)
{
	char	*temp;
	char	*charstr;
	int		i;

	i = 0;
	if (flag.zero == 1 && flag.minus == 0 && flag.decimal == 0)
		c = '0';
	temp = ft_strdup(*str);
	free(*str);
	charstr = malloc(sizeof(char) * (n + 1));
	if (!charstr)
		return (-1);
	while (i < n)
	{
		charstr[i] = c;
		i++;
	}
	charstr[i] = '\0';
	if (flag.minus == 1 && c != '0')
		*str = ft_strjoin(temp, charstr);
	else
		*str = ft_strjoin(charstr, temp);
	free(charstr);
	free(temp);
	return (i);
}

static char	*ft_puthexlow(unsigned long int num)
{
	char	x;
	int		i;
	int		j;
	char	*str;

	j = count_digits(num);
	str = malloc(j + 1);
	i = 0;
	str[0] = '0';
	if (num == 0)
		i++;
	if (!str)
		return (NULL);
	while (num > 0)
	{
		if ((num % 16) <= 9)
			x = (num % 16) + '0';
		if ((num % 16) >= 10 && (num % 16) <= 15)
			x = (num % 16) + 87;
		str[j - 1 - i] = x;
		i++;
		num /= 16;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_puthexhigh(unsigned long int num)
{
	char	x;
	int		i;
	int		j;
	char	*str;

	j = count_digits(num);
	str = malloc(j + 1);
	i = 0;
	str[0] = '0';
	if (num == 0)
		i++;
	if (!str)
		return (NULL);
	while (num > 0)
	{
		if ((num % 16) <= 9)
			x = (num % 16) + '0';
		if ((num % 16) >= 10 && (num % 16) <= 15)
			x = (num % 16) + 55;
		str[j - 1 - i] = x;
		i++;
		num /= 16;
	}
	str[i] = '\0';
	return (str);
}

int	x_flag(unsigned long int num, struct s_flags flag, char c)
{
	char	*str;
	int		slen;

	if (c == 'x')
		str = ft_puthexlow(num);
	if (c == 'X')
		str = ft_puthexhigh(num);
	if (num == 0 && flag.dot == 1 && flag.decimal == 0)
		str[0] = ' ';
	if (num == 0 && flag.dot == 1 && flag.decimal == 0 && flag.num == 0)
	{
		free(str);
		return (0);
	}
	slen = ft_strlen(str);
	if (flag.decimal > slen)
		slen += add_char_x((flag.decimal - slen), &str, '0', flag);
	if (flag.num > slen && flag.num > flag.decimal)
		slen += add_char_x((flag.num - slen), &str, ' ', flag);
	write(1, str, slen);
	free(str);
	return (slen);
}
