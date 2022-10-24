/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozgokme <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:24:34 by aozgokme          #+#    #+#             */
/*   Updated: 2022/02/26 13:24:37 by aozgokme         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*arr;
	int		i;
	int		j;

	arr = (char *)malloc(sizeof(char) * ft_strlen(str) + BUFFER_SIZE + 1);
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (str && str[i] != '\0')
		arr[j++] = str[i++];
	i = 0;
	while (buff[i] != '\0')
		arr[j++] = buff[i++];
	arr[j] = '\0';
	free(str);
	return (arr);
}
