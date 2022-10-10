/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:09 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/10 19:26:16 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Va leyendo la linea y la va metiendo en un malloc del tamaño del buffer + 1,
retorna toda la linea leida.*/
char	*ft_read_line(int fd, char *read_buffer)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(read_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(read);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, buffer);
	}
	free (read);
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read_buffer;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_buffer = ft_read_line(fd, read_buffer);
	if (!read_buffer)
		return (NULL);
	line = ft_get_the_line(read_buffer);
	read_buffer = ft_read_next_line(read_buffer);
	return (line);
}	
