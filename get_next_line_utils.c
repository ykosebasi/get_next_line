/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosebas <ykosebas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:20:09 by ykosebas          #+#    #+#             */
/*   Updated: 2026/03/13 15:49:49 by ykosebas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == b)
			return ((char *)&s[i]);
		i++;
	}
	if (b == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*total_str;

	if (!s1 || !s2)
		return (NULL);
	total_str = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!total_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		total_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		total_str[i] = s2[j];
		i++;
		j++;
	}
	total_str[i] = '\0';
	return (total_str);
}
char	*ft_strjoin_free(char *saved, char *buffer)
{
	char	*new_str;
	
	if (!saved)
	{
		saved = malloc(1);
		if (!saved)
			return (NULL);
		saved[0] = '\0';
	}
	if (!buffer)
	{
		free(saved);
		return (NULL);
	}
	new_str = ft_strjoin(saved, buffer);
	free(saved);
	return (new_str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) -start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}