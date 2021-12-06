/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_s_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 15:46:27 by mgroen        #+#    #+#                 */
/*   Updated: 2021/09/29 15:40:34 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_char_s(int n, char **str, char c, struct s_flags flag)
{
	char	*temp;
	char	*charstr;
	int		i;

	i = 0;
	if (flag.zero == 1 && flag.minus == 0)
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
	free(temp);
	free(charstr);
	return (i);
}

int	s_flag(char *str, struct s_flags flag)
{
	int		slen;
	char	*nstr;

	if (!str)
		str = ft_strdup("(null)");
	slen = ft_strlen(str);
	if (slen > flag.decimal && flag.dot == 1 && flag.decimal >= 0)
	{
		slen = 0;
		nstr = malloc(flag.decimal + 1);
		if (!nstr)
			return (-1);
		ft_strlcpy(nstr, str, flag.decimal + 1);
		nstr[flag.decimal + 1] = '\0';
		slen = ft_strlen(nstr);
	}
	else
		nstr = ft_strdup(str);
	if (!str)
		free(str);
	if (flag.num > slen)
		slen += add_char_s((flag.num - slen), &nstr, ' ', flag);
	write(1, nstr, ft_strlen(nstr));
	free(nstr);
	return (slen);
}

int	c_flag(char c, struct s_flags flag)
{
	char	*str;
	int		slen;

	str = ft_strdup(&c);
	if (c == '\0')
		str[0] = 'X';
	str[1] = '\0';
	slen = 1;
	if (flag.num > slen)
		slen += add_char_s((flag.num - 1), &str, ' ', flag);
	if (c == '\0')
	{
		if (flag.minus == 1 && c != '0')
			str[0] = '\0';
		else
		{
			if (flag.num == 0)
				str[0] = '\0';
			else
				str[flag.num - 1] = '\0';
		}
	}
	write(1, str, slen);
	free(str);
	return (slen);
}
