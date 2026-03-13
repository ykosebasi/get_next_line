/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosebas <ykosebas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:19:23 by ykosebas          #+#    #+#             */
/*   Updated: 2026/03/13 17:30:32 by ykosebas         ###   ########.fr       */
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

// get_line_from_saved(saved) ; Görevi: saved’in içindeki ilk satırı almak
// saved = "Hello World\n42 Istanbul\n" 
// get_line_from_saved(saved) → "Hello World\n"	!!Satırın sonunda \n dahil edilmeli
// Eğer son satır ve \n yoksa → kalan tüm saved döner


//saved_remaining(stash) ; Görevi: get_line_from_saved ile alınan kısmı saved’den kaldırmak ve güncellemek
//saved = "Hello World\n42 Istanbul\n"
//get_line_from_saved → "Hello World\n"
//saved_remaining (Geriye kalan)→ saved = "42 Istanbul\n"
//Eğer extract edilen satır saved’in tamamını kapsıyorsa → saved = NULL
//Artık saved bu kalan kısmı tutuyor, bir sonraki get_next_line çağrısında tekrar işlenir