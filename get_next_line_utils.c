/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:37:16 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/29 14:45:45 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// detects \n in string
int	is_line(char *string)
{
	int	i;
	
	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// copies and returns the string before & including \n
// moves the ptr of parameter string
char	*get_line(char *dst, char *src, int size)
{
	int					i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// returns the size of line including \n
int	get_linesize(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}

// function that appends a string to a new string
char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*newstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc(1 + s1_len + s2_len);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, s1_len);
	ft_memcpy(newstr + s1_len, s2, s2_len);
	newstr[s1_len + s2_len] = '\0';
	return (newstr);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	const unsigned char	*source;
	unsigned char		*destination;

	i = 0;
	source = src;
	destination = dst;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}