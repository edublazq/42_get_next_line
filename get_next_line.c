/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:37:43 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/09 22:37:44 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*buf;

	if (!fd)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (search_line(buf))
		
}
