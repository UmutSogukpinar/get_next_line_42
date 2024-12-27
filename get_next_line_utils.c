/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:51:35 by usogukpi          #+#    #+#             */
/*   Updated: 2024/12/27 12:06:32 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*arr;
	size_t	i;
	size_t	arr_index;

	i = 0;
	arr_index = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = malloc(total_size);
	if (arr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[arr_index++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		arr[arr_index++] = s2[i];
		i++;
	}
	arr[arr_index] = '\0';
	return (arr);
}

int	ft_is_newline_char(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	new_str = (char *) malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*ft_update_repo(char *total_line, char *repo)
{
	char	*new_repo;
	size_t	repo_len;
	size_t	line_len;

	repo_len = ft_strlen(repo);
	line_len = ft_strlen(total_line);
	new_repo = ft_substr(repo, line_len, repo_len - line_len);
	if (repo)
		free(repo);
	return (new_repo);
}
