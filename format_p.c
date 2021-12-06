/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 14:40:15 by mgroen        #+#    #+#                 */
/*   Updated: 2021/05/11 14:33:06 by mgroen        ########   odam.nl         */
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

static int	add_char_p(int n, char **str, char c, struct s_flags flag)
{
	char	*temp;
	char	*charstr;
	int		i;

	i = 0;
	if (flag.zero == 1 && flag.minus == 0 && flag.decimal == 0)
		c = '0';
	temp = ft_strdup(*str);
	charstr = malloc(sizeof(char) * (n + 1));
	if (!charstr)
		return (-1);
	free(*str);
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

static char	*ft_make_hex(unsigned long int num)
{
	char	x;
	int		i;
	int		j;
	char	*str;

	j = count_digits(num);
	str = malloc(j + 1);
	i = 0;
	if (!str)
		return (NULL);
	str[0] = '0';
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

int	p_flag(char *ptr, struct s_flags flag)
{
	unsigned long int	address;
	char				*str;
	char				*nstr;
	int					slen;

	slen = 2;
	address = (unsigned long int)ptr;
	if (!ptr && flag.dot == 1)
		str = ft_strdup("\0");
	else if (!ptr && flag.dot == 0)
		str = ft_strdup("0");
	else
		str = ft_make_hex(address);
	slen += ft_strlen(str);
	if (flag.decimal > slen)
		slen += add_char_p((flag.decimal - slen + 2), &str, '0', flag);
	nstr = ft_strjoin("0x", str);
	free(str);
	if (flag.num > slen && flag.num > flag.decimal)
		slen += add_char_p((flag.num - slen), &nstr, ' ', flag);
	write(1, nstr, slen);
	free(nstr);
	return (slen);
}
