/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/29 17:36:35 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to the beginning of the line
NULL on error or if no more next line
Use only read(), malloc(), free()
*/

#include "get_next_line.h"

static char	*update_data(char *string, int size);
char		*save_chars(int fd, char *saved_data, int *size);
static void	free_alldata(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*saved_data;
	char		*line;
	int			linesize;
	char		*remainder;
    int         size;

    size = 1;
	while (!is_line(saved_data) && size != 0)
	{
		saved_data = save_chars(fd, saved_data, &size);
		if (!saved_data)
			return (NULL);
		// if (size == 0)
		// 	break ;
	}
	linesize = get_linesize(saved_data);
	line = malloc(linesize + 1);
	if (!line)
		return (NULL);
	line = get_line(line, saved_data, linesize);
	remainder = update_data(saved_data, linesize);
	free(saved_data);
	if (!remainder)
		saved_data = NULL;
	saved_data = remainder;
	return (line);
}

char	*save_chars(int fd, char *saved_data, int *size)
{
	char	*buffer;
	char	*joined;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*size = read(fd, buffer, BUFFER_SIZE);
	if (*size > 0)
	{
		buffer[*size] = '\0';
		joined = ft_strjoin(saved_data, buffer);
		if (joined)
		{
			free_alldata(saved_data, buffer);
			return (joined);
		}
	}
	else if (*size == 0)
	{
		free(buffer);
		return (saved_data);
	}
	free_alldata(saved_data, buffer);
	return (NULL);
}

static void	free_alldata(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

static char	*update_data(char *string, int size)
{
	char	*start;
	int		length;
	char	*remainder;

	start = string + size;
	length = ft_strlen(start);
	if (length == 0)
		return (NULL);
	remainder = malloc(length + 1);
	if (!remainder)
		return (NULL);
	ft_memcpy(remainder, start, length);
	remainder[length] = '\0';
	return (remainder);
}

/*
int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("test/test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (1);        
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);      
	}
	close(fd);
	return(0);
}
*/