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

char	*new_hold(char *hold, int fd, int *read_info)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*read_info = read(fd, buffer, BUFFER_SIZE);
	if (*read_info == -1)
		return (NULL);
	if (ft_strchr(buffer, '\n') != buffer)
		return (ft_strjoin(hold, buffer));
	while (ft_strchr(buffer, '\n') == buffer)
	{
		if (*read_info == 0)
		{
			hold = ft_strjoin(hold, buffer);
			return (hold);
		}
		hold = ft_strjoin(hold, buffer);
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		*read_info = read(fd, buffer, BUFFER_SIZE);
	}
	return (hold);
}

char	*search_hold(char *hold)
{
	char	*end;
	size_t	i;

	i = 0;
	end = ft_strchr(hold, '\n');
	if (end == hold)
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*hold;
	int			read_info;

	read_info = 0;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	hold = new_hold(hold, fd, &read_info);
	if (!hold)
		return (NULL);
	if (read_info == 0)
	{
		output = ft_strdup(hold);
		free(hold);
		return (output);
	}
	output = search_hold(hold);
	if (!output)
		return (NULL);
	
	return (output);
}

#include <stdio.h>

int	main(void)
{
	int fd = open("hola.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
