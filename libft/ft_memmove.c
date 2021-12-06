/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:39:55 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 15:04:24 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (dest == NULL && src == NULL && n > 0)
		return (dest);
	else if (cdest < csrc)
		ft_memcpy(cdest, csrc, n);
	else
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	}
	return ((char *)dest);
}
