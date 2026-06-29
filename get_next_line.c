/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosebas <ykosebas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:35:49 by ykosebas          #+#    #+#             */
/*   Updated: 2026/06/29 18:29:04 by ykosebas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *saved)
{
	char		*buffer;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(saved, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(saved);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		saved = ft_strjoin_free(saved, buffer);
	}
	free(buffer);
	return (saved);
}

char	*get_line_from_saved(char *saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved || !saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	return (line);
}

char	*saved_remaining(char *saved)
{
	int		i;
	char	*remain_saved;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	if (saved[i + 1] == '\0')
	{
		free(saved);
		return (NULL);
	}
	remain_saved = ft_substr(saved, i + 1, ft_strlen(saved) - (i + 1));
	free(saved);
	return (remain_saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_save(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line_from_saved(saved);
	saved = saved_remaining(saved);
	return (line);
}
