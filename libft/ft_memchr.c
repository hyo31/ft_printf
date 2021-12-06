/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:38:35 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 15:18:12 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cstr;

	cstr = (unsigned char *)s;
	while (n > 0)
	{
		if (*cstr != (unsigned char)c)
		{
			cstr++;
			n--;
		}
		else
			return (cstr);
	}
	return (0);
}
