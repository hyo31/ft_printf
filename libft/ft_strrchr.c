/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:21:15 by milan         #+#    #+#                 */
/*   Updated: 2020/11/05 16:29:30 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*cs;
	int		l;

	i = 0;
	j = -1;
	cs = (char *)s;
	l = 0;
	while (cs[l] != '\0')
		l++;
	while (i <= l)
	{
		if (cs[i] == c)
			j = i;
		i++;
	}
	if (j == -1)
		return (0);
	cs = (cs + j);
	return (cs);
}
