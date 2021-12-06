/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:24:04 by mgroen        #+#    #+#                 */
/*   Updated: 2020/11/11 12:46:19 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		sub_s = malloc(ft_strlen(s) - start + 1);
	else
		sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		sub_s[i] = s[i + start];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
