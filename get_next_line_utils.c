/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozgokme <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:25:02 by aozgokme          #+#    #+#             */
/*   Updated: 2022/02/26 13:25:06 by aozgokme         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *temp_str)
{
	char	*arr;
	int		i;
	int		j;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !temp_str)
		return (0);
	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * \
			ft_strlen(str) + ft_strlen(temp_str) + 1);
	while (str[j] != '\0')
		arr[i++] = str[j++];
	j = 0;
	while (temp_str[j] != '\0')
		arr[i++] = temp_str[j++];
	arr[i] = '\0';
	free(str);
	return (arr);
}
