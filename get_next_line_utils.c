/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:47:40 by rukabash          #+#    #+#             */
/*   Updated: 2024/07/29 16:42:02 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 関数: ft_strlen
// 目的: 文字列の長さを計算します。
// 引数: char *str - 長さを計算する文字列。
// 戻り値: 文字列の長さ（null文字までの文字数）。
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

// 関数: ft_strjoin
// 目的: 2つの文字列を結合し、新しい文字列を返します。
// 引数: char *s1 - 最初の文字列、char *s2 - 2番目の文字列。
// 戻り値: 結合された新しい文字列。
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// 関数: ft_getline
// 目的: 文字列から最初の行を抽出します。
// 引数: char *str - 元の文字列。
// 戻り値: 最初の行を含む新しい文字列。
char	*ft_getline(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (str[j] == '\0')
		line = malloc(sizeof(char) * (j + 1));
	else
		line = malloc(sizeof(char) * (j + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// 関数: ft_trimline
// 目的: 文字列から最初の行を削除し、残りの部分を新しい文字列として返します。
// 引数: char *str - 元の文字列。
// 戻り値: 最初の行を削除した後の新しい文字列。
char	*ft_trimline(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
	{
		line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}

// 関数: get_next_line
// 目的: ファイルディスクリプタから次の行を読み取ります。
// 引数: int fd - ファイルディスクリプタ。
// 戻り値: 次の行を含む新しい文字列。
char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	int			linesize;
	int			read_size;
	static char	*str;
	int			i;
	int			j;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0 || read_size >= 21474147)
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
	int		fd;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("1 ; %s\n", line);
	return (0);
}
