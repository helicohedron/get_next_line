/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:29 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/25 23:11:59 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to the beginning of the line
NULL on error or if no more next line
Use only read(), malloc(), free()
*/

#include "get_next_line.h"

static char    *update_data(char *string, int size);

char *get_next_line(int fd)
{
	static char	*saved_data;
	char		*buffer;
	int			size;
	char		*line;
	int			linesize;
    char        *temp;
    char        *remainder;
    char        *joined;

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
			joined = ft_strjoin(saved_data, buffer);
            if (joined)
            {
                free(saved_data);                
                saved_data = joined;
            }
            else
            {
                free(saved_data);
                free(buffer);
                saved_data = NULL;
                return (NULL);
            }
        }
        else if (size == 0)
		{
			free(buffer);
            temp = saved_data; //prevent dangling ptr when freed in main()
            saved_data = NULL;			
			return (temp);
		}
        else
        {
            free(buffer);
            free(saved_data);
            saved_data = NULL;
            return (NULL);
        }    
	}

	linesize = get_linesize(saved_data);
	line = malloc(linesize + 1);
    if (!line)
        return (NULL);
	line = get_line(line, saved_data, linesize);
    remainder = update_data(saved_data, linesize);
    if (!remainder)
    {
        free(saved_data);
        saved_data = NULL;
        return (line);        
    }
    free(saved_data);
    saved_data = remainder;
	return (line);
}

// function that returns a copy of string in saved_data that you get moving the ptr linesize times
static char    *update_data(char *string, int size)
{
    char    *start;
    int     length;
    char    *remainder;
    
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

	fd = open("test.txt", O_RDONLY);
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
