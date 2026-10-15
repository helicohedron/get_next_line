/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/15 19:02:00 by jrosette         ###   ########.fr       */
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
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
		{
			free(buffer);			
			return ;
		}
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ; // or free and return?
		else
			saved_data = append_str(buffer);
	}

	line = get_line(saved_data);
	free(buffer);
	return (line);
}
