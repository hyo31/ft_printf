/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgroen <mgroen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 14:12:39 by mgroen        #+#    #+#                 */
/*   Updated: 2021/03/08 15:11:34 by milan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	lenleft(char const *s1, char const *set)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s1);
	while (i <= l && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	return (i);
}

static int	lenright(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i >= 0 && ft_strchr(set, s1[i]) != NULL)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!(s1))
		return (NULL);
	start = lenleft(s1, set);
	end = lenright(s1, set);
	if (start > end)
		return (ft_strdup(""));
	new_str = malloc(end - start + 2);
	if (!new_str)
		return (NULL);
	while ((start + i) <= end)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
