/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:40:56 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 15:07:22 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	len;

	i = 0;
	l = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dst == 0 && size == 0)
		return (len);
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[l] != '\0' && (i + l + 1) < size)
	{
		dst[i + l] = src[l];
		l++;
	}
	if (i < size)
		dst[i + l] = '\0';
	return (i + len);
}
