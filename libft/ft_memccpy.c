/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:38:05 by milan         #+#    #+#                 */
/*   Updated: 2020/11/10 14:57:38 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *str_dest, const void *str_src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;
	char	*ptr;

	dest = (char *)str_dest;
	src = (char *)str_src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest[i] = src[i];
		if (src[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
