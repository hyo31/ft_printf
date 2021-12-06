/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:37:15 by milan         #+#    #+#                 */
/*   Updated: 2021/03/08 14:55:46 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	str = malloc(count * size);
	i = 0;
	if (str == 0)
		return (str);
	while (i < (count * size))
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
