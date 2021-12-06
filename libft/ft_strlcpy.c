/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:41:32 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 15:07:37 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*e;
	const char	*s;

	d = (char *)dst;
	e = (char *)dst + size;
	s = (const char *)src;
	while (*s != '\0' && d < e)
	{
		*d = *s;
		d++;
		s++;
	}
	if (d < e)
		*d = 0;
	else if (size > 0)
		d[-1] = 0;
	while (*s != '\0')
		s++;
	return (s - src);
}
