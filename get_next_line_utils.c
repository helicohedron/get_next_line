/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:37:16 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/15 19:04:26 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// detects \n or EOF in string
int	is_line(char *string)
{
	int	i;
	
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n' || string[i++] == '\0')
			return (1);
		i++;
	}
	return (0);
}

// copies and returns the string before & including \n or \0
// moves the ptr of parameter string
char	*get_line(char *string)
{
	char	*copy;

	while (*string != '\n' && *string != '\0')
	{
		*copy = *string;
		string++;
		copy++;
	}
	if (*string == '\n')
	{
		*copy = '\n';
		string++;		
	}
	else if (*string == '\0')
		*copy = '\0';
	return (copy);
}

// function that appends a string to a new string
char	*append_string(char *string)
{
	
}