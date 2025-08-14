/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkara <bkara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:22:17 by bkara             #+#    #+#             */
/*   Updated: 2025/08/14 21:05:48 by bkara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(char *stash, int fd)
{
	char	*temp_stash;
	char	*temp;
	ssize_t	byte_read;

	temp_stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_stash)
		return (NULL);
	byte_read = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && byte_read > 0)
	{
		byte_read = read(fd, temp_stash, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(temp_stash), free(stash), NULL);
		if (byte_read == 0)
			break ;
		temp_stash[byte_read] = '\0';
		temp = ft_strjoin(stash, temp_stash);
		if (!temp)
			return (free(temp_stash), free(stash), NULL);
		free(stash);
		stash = temp;
	}
	return (free(temp_stash), stash);
}

static char	*ft_get_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_remainder(char *stash)
{
	char	*remainder;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	remainder = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!remainder)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		remainder[j++] = stash[i++];
	remainder[j] = '\0';
	free(stash);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_file(stash, fd);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_remainder(stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
