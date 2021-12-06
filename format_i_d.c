/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_i_d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 15:47:08 by mgroen        #+#    #+#                 */
/*   Updated: 2021/09/29 16:07:27 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	swap_min_zero(char **temp, char c, struct s_flags flag)
{
	if (*temp[0] == '-' && c == '0' && (flag.zero == 1 || flag.dot == 1))
	{
		*temp[0] = c;
		return ('-');
	}
	else
		return (c);
}

static char	*get_charstr(int n, char c)
{
	char	*charstr;
	int		i;

	i = 0;
	charstr = malloc(sizeof(char) * (n + 1));
	if (!charstr)
		return (NULL);
	while (i < n)
	{
		charstr[i] = c;
		i++;
	}
	charstr[i] = '\0';
	return (charstr);
}

static int	add_char_i_d(int n, char **str, char c, struct s_flags flag)
{
	char	*temp;
	char	*charstr;
	int		i;

	i = 0;
	if (flag.zero == 1 && flag.minus == 0 && flag.decimal <= 0)
		c = '0';
	temp = ft_strdup(*str);
	free(*str);
	charstr = get_charstr(n, c);
	charstr[0] = swap_min_zero(&temp, c, flag);
	if (flag.minus == 1 && c != '0')
		*str = ft_strjoin(temp, charstr);
	else
		*str = ft_strjoin(charstr, temp);
	free(temp);
	free(charstr);
	return (n);
}

int	i_d_flag(int num, struct s_flags flag)
{
	char	*str;
	int		slen;

	str = ft_itoa(num);
	if (num == 0 && flag.dot == 1 && flag.decimal == 0)
		str[0] = ' ';
	if (num == 0 && flag.dot == 1 && flag.decimal == 0 && flag.num == 0)
	{
		free(str);
		return (0);
	}
	slen = ft_strlen(str);
	if (num < 0 && flag.decimal > 0)
		slen--;
	if (flag.decimal > slen)
		slen += add_char_i_d((flag.decimal - slen), &str, '0', flag);
	if (num < 0 && flag.decimal > 0)
		slen++;
	if (flag.num > slen && flag.num > flag.decimal)
		slen += add_char_i_d((flag.num - slen), &str, ' ', flag);
	write(1, str, ft_strlen(str));
	free(str);
	return (slen);
}
