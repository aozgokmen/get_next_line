/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozgokme <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:23:42 by aozgokme          #+#    #+#             */
/*   Updated: 2022/02/26 13:23:46 by aozgokme         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!new_str)
		return (0);
	i++;
	j = 0;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		line[i++] = str[j++];
	if (str[j] == '\n')
		line[i++] = str[j];
	line[i] = '\0';
	return (line);
}

char	*get_str(int fd, char *str)
{
	char	*buff;
	int		read_byte;

	read_byte = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!ft_strchr(str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;

	if (fd == -1 && BUFFER_SIZE <= 0)
	{
		free(str);
		return (0);
	}
	str[fd] = get_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = get_line(str[fd]);
	str[fd] = get_next_new_str(str[fd]);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	size_t	i;
	int		fd;
	int		fd2;

	i = 4;
	fd = open("text.txt",O_CREAT | O_RDONLY, 0777);
	fd2 = open("text2.txt",O_CREAT | O_RDONLY, 0777);
	while (i--)
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
	close (fd);
	return (0);
}
*/
