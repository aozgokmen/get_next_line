/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozgokme <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:25:29 by aozgokme          #+#    #+#             */
/*   Updated: 2022/02/26 13:25:33 by aozgokme         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{	
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_new_str(char *str)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = ft_strlen(str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	new_line = (char *)malloc(sizeof(char) * (j - i) + 1);
	if (!new_line)
		return (0);
	j = 0;
	i++;
	while (str[i] != '\0')
		new_line[j++] = str[i++];
	new_line[j] = '\0';
	free(str);
	return (new_line);
}

char	*ft_get_str(int fd, char *str)
{
	int		read_byte;
	char	*temp_str;

	temp_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_str)
		return (0);
	read_byte = 1;
	while (!ft_strchr(str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, temp_str, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (temp_str);
			return (0);
		}
		temp_str[read_byte] = '\0';
		str = ft_strjoin(str, temp_str);
	}
	free(temp_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_str(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_get_new_str(str);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	size_t	i;
	int		fd;

	i = 4;
	fd = open ("test.txt", O_CREAT | O_RDONLY, 0777);
	while(i--)
	{
		printf("%s", get_next_line(fd)); 
	}
	close (fd);
	return (0);
}
*/
