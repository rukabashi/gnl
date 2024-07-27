/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:47:38 by rukabash          #+#    #+#             */
/*   Updated: 2024/07/24 15:20:10 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	int			linesize;
	int			read_size;
	static char	*str;
	int			i;
	int			j;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_size] = '\0';
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	linesize = ft_strlen(buffer);
	line = malloc(sizeof(char) * (linesize + 1));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[linesize] = '\0';
	free(buffer);
	j = 0;
	while (str[i] != '\0')
	{
		str[j] = str[j];
		j++;
	}
	free(str);
	return (line);
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	// char	*line1;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	// line1 = get_next_line(fd);
	printf("1 ; %s\n", line);
	// printf("2 ; %s\n", line1);
	// printf("%s\n", line);
	return (0);
}
