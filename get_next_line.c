/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosebas <ykosebas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:19:23 by ykosebas          #+#    #+#             */
/*   Updated: 2026/03/12 15:49:24 by ykosebas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	int			bytes_read;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(saved, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	line = get_line_from_saved(saved);   // saved’in içinden ilk satırı al
	saved = saved_remaining(saved);     // satırı saved’den çıkar, kalan veriyi tut
	return (line);
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