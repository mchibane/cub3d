/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:29 by mchibane          #+#    #+#             */
/*   Updated: 2021/09/27 20:14:30 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_newline(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	set_line(char *save, char *buff, char **line)
{
	int	nl_index;
	int	ret;

	ret = 0;
	nl_index = ft_newline(save);
	if (nl_index > -1)
	{
		*line = ft_substr(save, 0, nl_index);
		if (!(*line))
			return (-1);
		ft_strlcpy(buff, &save[nl_index + 1], BUFFER_SIZE + 1);
		ret = 1;
	}
	else
	{
		nl_index = ft_strlen(save) - 1;
		*line = ft_substr(save, 0, nl_index + 1);
		if (!(*line))
			return (-1);
		ft_strlcpy(buff, &save[nl_index + 1], BUFFER_SIZE + 1);
	}
	return (ret);
}

int	read_content(int fd, char **save, char *buff)
{
	int		ret;
	char	*tmp;

	ret = 1;
	while ((ft_newline(*save) == -1) && (ret != 0))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		tmp = *save;
		*save = ft_strjoin(tmp, buff);
		if (!(*save))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[FD_MAX][BUFFER_SIZE + 1];
	char		*save;
	int			b_read;

	b_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	save = ft_strdup(buff[fd]);
	if (!save)
		return (-1);
	if (ft_newline(save) > -1)
		b_read = set_line(save, buff[fd], line);
	else
	{
		b_read = read_content(fd, &save, buff[fd]);
		set_line(save, buff[fd], line);
	}
	free(save);
	return (b_read);
}
