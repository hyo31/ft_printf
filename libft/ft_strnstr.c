/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:53:57 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 15:08:42 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	l = 0;
	if (little[0] == '\0')
		return (big);
	while (big[l] != '\0' && l < len)
	{
		i = 0;
		while (big[l + i] == little[i] && i + l < len)
		{
			i++;
			if (little[i] == '\0')
			{
				big = (big + l);
				return (big);
			}
		}
		l++;
	}
	return (0);
}
