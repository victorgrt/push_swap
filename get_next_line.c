/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:59:44 by victor            #+#    #+#             */
/*   Updated: 2023/03/23 11:30:29 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	laftmagicderuru(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*recupfile(char *save)
{
	char	*lu;
	int		ouvert;

	lu = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lu)
		return (NULL);
	ouvert = 1;
	while (laftmagicderuru(save) == 0 && ouvert > 0)
	{
		ouvert = read(0, lu, BUFFER_SIZE);
		if (ouvert < 0)
		{
			free(lu);
			return (NULL);
		}
		lu[ouvert] = 0;
		save = ft_strjoin2(save, lu);
	}
	free(lu);
	return (save);
}

char	*recupline(char *save)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	if (save == NULL)
		return (NULL);
	if (save[len] == 0)
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*trimming_static(char *save)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (ft_strlen2(save) == 0)
		return (free(save), NULL);
	buff = malloc(sizeof(char) * (ft_strlen2(save) - i + 1));
	if (!buff)
		return (free(save), NULL);
	j = 0;
	while (save[i] != '\0')
	{
		buff[j] = save[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	return (free(save), buff);
}

char	*get_next_line(int fd, int flag)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (flag == 1)
		return (free(save), NULL);
	save = recupfile(save);
	line = recupline(save);
	save = trimming_static(save);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	// int	i = 1;
// 	char	*res;
// 	fd = open("test.txt", O_RDONLY);
// 	res = get_next_line(fd);
// 	while (res)
// 	{
// 		printf("%s", res);
// 		free(res);
// 		res = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }