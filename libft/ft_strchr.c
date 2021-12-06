/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:16:41 by milan         #+#    #+#                 */
/*   Updated: 2020/11/05 10:45:12 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		l;
	int		i;
	char	*cs;

	l = 0;
	i = 0;
	cs = (char *)s;
	while (cs[l] != '\0')
		l++;
	while (i <= l)
	{
		if (cs[i] == c)
			return (&cs[i]);
		i++;
	}
	return (0);
}
