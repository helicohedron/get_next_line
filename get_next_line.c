/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/19 15:34:20 by jrosette         ###   ########.fr       */
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
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
		{
			//free(buffer);			
			return (NULL);
		}
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ; // or free and return?
		else
			saved_data = ft_strjoin(saved_data, buffer);
	}

	linesize = get_linesize(saved_data);
	line = malloc(linesize + 1);
	line = get_line(line, saved_data, linesize);
	free(buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	char *line;
	
	fd = open("test.txt", O_RDONLY | O_CREAT );
	if (fd == -1)
		printf("Error");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return(0);
}
