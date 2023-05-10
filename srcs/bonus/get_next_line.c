/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 06:35:41 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/29 06:04:21 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	*debut_nouvelle_ligne(char *big_str)
{
	int		i;
	int		j;
	char	*debut_new_line;

	i = 0;
	while (big_str[i] && big_str[i] != '\n')
		i++;
	if (big_str[i] == '\n')
		i++;
	if (!big_str[i])
	{
		free(big_str);
		return (NULL);
	}
	debut_new_line = malloc(sizeof(char) * (ft_strlen(big_str) - i + 1));
	if (!debut_new_line)
		return (NULL);
	j = 0;
	while (big_str[i])
		debut_new_line[j++] = big_str[i++];
	debut_new_line[j] = '\0';
	free(big_str);
	return (debut_new_line);
}

char	*extirpation_ligne(char *big_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!big_str[i])
		return (NULL);
	while (big_str[i] && big_str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (big_str[i] && big_str[i] != '\n')
	{
		line[i] = big_str[i];
		i++;
	}
	if (big_str[i] == '\n')
	{
		line[i] = big_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*lecture_du_fd(int fd, char *big_str)
{
	int		rd_bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(big_str);
		return (NULL);
	}
	rd_bytes = 1;
	while (!ft_strchr(big_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(buffer), free(big_str), NULL);
		buffer[rd_bytes] = '\0';
		big_str = ft_strjoin(big_str, buffer);
		if (!big_str)
			return (NULL);
	}
	free(buffer);
	return (big_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*big_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!big_str)
	{
		big_str = malloc(1 * sizeof(char));
		if (!big_str)
			return (NULL);
		big_str[0] = '\0';
	}
	big_str = lecture_du_fd(fd, big_str);
	if (!big_str)
		return (NULL);
	line = extirpation_ligne(big_str);
	big_str = debut_nouvelle_ligne(big_str);
	return (line);
}
