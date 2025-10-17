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

char	*new_hold(char *hold, int fd)
{
	char	*buffer;
	int		read_info;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_info = read(fd, buffer, BUFFER_SIZE);
	
}

char	*search_hold(char *hold)
{
	char	*output;
	size_t	i;
	size_t	hold_length;

	i = 0;
	hold_length = ft_strlen(hold);
	while (hold[i])
	{
		if (hold[i] == '\n')
			break ;
		i++;
	}
	if (i == hold_length)
		return (NULL);
	output = (char *)malloc(hold_length - i + 1);
	if (!output)
		return (NULL);
	output[i + 1] = '\0';
	while (i != 0)
	{
		output[i] = hold[i];
		i--;
	}
	return (output);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*hold;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!hold)
		hold = new_hold(fd);
	if (!hold)
		return (NULL);
	output = search_hold(hold);
	if (!output)
		return (NULL);
	free(hold);
	return (output);
}

#include <stdio.h>

int	main(void)
{
	int fd = open("hola.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
