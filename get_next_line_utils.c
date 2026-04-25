/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosebas <ykosebas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:20:09 by ykosebas          #+#    #+#             */
/*   Updated: 2026/04/13 17:38:32 by ykosebas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	if (!s)
		return (NULL);
	b = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == b)
			return ((char *)&s[i]);
		i++;
	}
	if (b == '\0')
		return ((char *)&s[i]);
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
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
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
