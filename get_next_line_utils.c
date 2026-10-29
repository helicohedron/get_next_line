/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:37:16 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/29 18:34:43 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

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
