/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:38:06 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/09 22:38:06 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
