/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 14:37:15 by mgroen        #+#    #+#                 */
/*   Updated: 2021/09/09 17:32:02 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	check_format(const char **str, va_list ap, struct s_flags flag)
{
	int	len;

	len = 0;
	if (**str == 'c')
		len = c_flag(va_arg(ap, int), flag);
	else if (**str == 's')
		len = s_flag(va_arg(ap, char *), flag);
	else if (**str == 'p')
		len = p_flag(va_arg(ap, void *), flag);
	else if (**str == 'd')
		len = i_d_flag(va_arg(ap, int), flag);
	else if (**str == 'i')
		len = i_d_flag(va_arg(ap, int), flag);
	else if (**str == 'u')
		len = u_flag(va_arg(ap, unsigned int), flag);
	else if (**str == 'x')
		len = x_flag(va_arg(ap, unsigned int), flag, 'x');
	else if (**str == 'X')
		len = x_flag(va_arg(ap, unsigned int), flag, 'X');
	else if (**str == '%')
		len = c_flag('%', flag);
	else
		len = -1;
	return (len);
}

static void	get_flag_number(const char *str,
					struct s_flags *flag, va_list ap)
{
	if (*str != '*')
	{
		if (flag->dot == 0)
		{
			flag->num *= 10;
			flag->num += (*str - '0');
		}
		if (flag->dot == 1)
		{
			flag->decimal *= 10;
			flag->decimal += (*str - '0');
		}
	}
	else
	{
		if (flag->dot == 0)
			flag->num = va_arg(ap, int);
		if (flag->dot == 1)
			flag->decimal = va_arg(ap, int);
	}
	if (flag->num < 0)
	{
		flag->num *= -1;
		flag->minus = 1;
	}
}

static int	check_flag(const char *str, va_list ap)
{
	struct s_flags	flag;

	flag.num = 0;
	flag.decimal = 0;
	flag.asterisk = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.dot = 0;
	while (*str == '.' || *str == '*' || *str == '-'
		|| (*str >= '0' && *str <= '9'))
	{
		if (*str == '.')
			flag.dot = 1;
		if (*str == '*')
			flag.asterisk = 1;
		if (*str == '-')
			flag.minus = 1;
		if (*str == '0' && flag.num == 0 && flag.decimal == 0)
			flag.zero = 1;
		if ((*str >= '0' && *str <= '9') || *str == '*')
			get_flag_number(str, &flag, ap);
		str++;
	}
	return (check_format(&str, ap, flag));
}

static int	ft_make_format(int *len, const char *str, va_list ap)
{
	int	i;
	int	ret;

	i = 1;
	*len += 0;
	ret = check_flag(str + 1, ap);
	if (ret != -1)
	{
		*len += ret - 1;
		while (str[i] == '.' || str[i] == '*'
			|| str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		i++;
	}
	else
		*len -= 1;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			i = ft_make_format(&len, str, ap);
			while (i > 1)
			{
				str++;
				i--;
			}
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
		len++;
	}
	va_end(ap);
	return (len);
}
