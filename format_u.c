/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 16:20:53 by milan         #+#    #+#                 */
/*   Updated: 2021/09/29 15:45:55 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_str(char *str, unsigned int n, int i)
{
	int	j;

	j = 0;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i - j] = ((n % 10) + '0');
		n /= 10;
		j++;
	}
	return (str);
}

static char	*ft_u_itoa(unsigned int n)
{
	char			*str;
	int				i;
	unsigned int	count;

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

int	add_char_u(int n, char **str, char c, struct s_flags flag)
{
	char	*temp;
	char	*charstr;
	int		i;

	i = 0;
	if (flag.zero == 1 && flag.minus == 0 && flag.decimal <= 0)
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

int	u_flag(unsigned int num, struct s_flags flag)
{
	char	*str;
	int		slen;

	str = ft_u_itoa(num);
	if (num == 0 && flag.dot == 1 && flag.decimal == 0)
		str[0] = ' ';
	if (num == 0 && flag.dot == 1 && flag.decimal == 0 && flag.num == 0)
	{
		free(str);
		return (0);
	}
	slen = ft_strlen(str);
	if (flag.decimal > slen)
		add_char_u((flag.decimal - slen), &str, '0', flag);
	slen = ft_strlen(str);
	if (flag.num > slen && flag.num > flag.decimal)
		slen += add_char_u((flag.num - slen), &str, ' ', flag);
	write(1, str, ft_strlen(str));
	free(str);
	return (slen);
}
