/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:37:09 by jrosette          #+#    #+#             */
/*   Updated: 2026/10/15 19:03:42 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

int		is_line(char *string);
char	*get_line(char *string);
char	*append_string(char *string);

# endif
#endif