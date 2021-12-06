/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 14:02:39 by mgroen        #+#    #+#                 */
/*   Updated: 2021/09/29 14:01:49 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1 || !s2)
		return (0);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (0);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2[l] != '\0')
	{
		new_str[i + l] = s2[l];
		l++;
	}
	new_str[i + l] = '\0';
	return (new_str);
}
