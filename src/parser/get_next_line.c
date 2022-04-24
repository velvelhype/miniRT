/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:58:53 by akito             #+#    #+#             */
/*   Updated: 2022/04/10 14:24:39by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

static char	*gnl_from_memo(char **memo, const char *tail_ptr);
static char	*ft_strmerge(char **s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*memo[FD_SIZE] = {NULL};
	char		*buf;
	ssize_t		read_size;

	if (memo[fd] != NULL && ft_strchr(memo[fd], '\n') != NULL)
		return (gnl_from_memo(&memo[fd], ft_strchr(memo[fd], '\n')));
	while (1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1LL));
		if (buf == NULL)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(buf);
			if (memo[fd] == NULL)
				return (NULL);
			return (gnl_from_memo(&memo[fd], memo[fd] + ft_strlen(memo[fd])));
		}
		buf[read_size] = '\0';
		if (ft_strmerge(&memo[fd], buf) == NULL)
			return (NULL);
		if (ft_strchr(memo[fd], '\n') != NULL)
			return (gnl_from_memo(&memo[fd], ft_strchr(memo[fd], '\n')));
	}
}

static char	*gnl_from_memo(char **memo, const char *tail_ptr)
{
	char	*new_line;
	char	*second_line;

	if (*memo == NULL || tail_ptr == NULL)
		return (NULL);
	new_line = ft_substr(*memo, 0, tail_ptr - *memo + 1);
	second_line = ft_substr(tail_ptr, 1, SIZE_MAX / 4LL);
	free(*memo);
	*memo = NULL;
	if (second_line == NULL || second_line[0] == '\0')
	{
		free(second_line);
		second_line = NULL;
	}
	else
		*memo = second_line;
	return (new_line);
}

static char	*ft_strmerge(char **s1, char *s2)
{
	char	*merged_str;

	merged_str = ft_strjoin(*s1, s2);
	free(*s1);
	free(s2);
	*s1 = merged_str;
	return (*s1);
}
