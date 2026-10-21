/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/21 13:53:32 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to the beginning of the line
NULL on error or if no more next line
Use only read(), malloc(), free()
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*saved_data;
	char		*buffer;
	int			size;
	char		*line;
	int			linesize;

	// check if saved_data has newline or EOF
	while (!is_line(saved_data))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)		
			return (NULL);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size > 0)
        {
            buffer[size] = '\0'; // null terminate the buffer           
			saved_data = ft_strjoin(saved_data, buffer);
        }
        else if (size == 0)
		{
			free(buffer);			
			return (saved_data); // should you return saved_data?
		}
        else
        {
            free(buffer);
            return (NULL);
        }    
	}

	linesize = get_linesize(saved_data);
	line = malloc(linesize + 1);
	line = get_line(line, saved_data, linesize);
	free(buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return(0);
}
