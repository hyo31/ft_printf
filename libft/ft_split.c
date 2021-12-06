/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 19:00:12 by milan         #+#    #+#                 */
/*   Updated: 2021/05/11 14:27:12 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	i;
	int	num_words;

	i = 0;
	num_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_words++;
		i++;
	}
	return (num_words);
}

static char	*find_pos(const char *s, int row, char c)
{
	int	i;

	i = 1;
	while (s[i - 1] == c && s[i] == c)
		i++;
	if (s[i - 1] == c && s[i] != c)
		return ((char *)&s[i]);
	while (s[i] != '\0')
	{
		if (row == 0 && i == 1)
			return ((char *)&s[i - 1]);
		if (s[i - 1] == c && s[i] != c)
			return ((char *)&s[i]);
		while (s[i] == c && s[i + 1] == c)
			i++;
		i++;
	}
	return ((char *)s);
}

static void	clean_str(char **new_strings, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(new_strings[i]);
		i++;
	}
	free(new_strings);
	return ;
}

static char	*copy_string(const char *s, char c, char **new_strings, int row)
{
	int		len;
	int		i;
	char	*string;

	len = 0;
	i = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	string = malloc(len + 1);
	if (!string)
	{
		clean_str(new_strings, row);
		return (NULL);
	}
	while (i < len)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(const char *s, char c)
{
	int		row;
	int		num_words;
	char	**new_strings;

	row = 0;
	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	new_strings = malloc(sizeof(char *) * (num_words + 1));
	if (!new_strings)
		return (NULL);
	while (row < num_words)
	{
		s = find_pos(s, row, c);
		new_strings[row] = copy_string(s, c, new_strings, row);
		if (!new_strings)
			return (NULL);
		row++;
	}
	new_strings[row] = NULL;
	return (new_strings);
}
