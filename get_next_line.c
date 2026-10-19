/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/19 20:08:23 by camille          ###   ########.fr       */
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

	// check if saved_data has newline or EOF
	while (!is_line(saved_data))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			//free(buffer);			
			return (NULL);
		}
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == 0)
			return (saved_data);
		else if (size > 0)
        {
			saved_data = ft_strjoin(saved_data, buffer);
            buffer[BUFFER_SIZE] = '\0';            
        }
        else
        {
            free(buffer);
            return (NULL);
        }    
	}

	line = get_line(saved_data);
	free(buffer);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error");
	printf("%s", get_next_line(fd));
	return(0);
}
