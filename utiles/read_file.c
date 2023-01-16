/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:46:37 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/11 05:31:45 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_file(int fd)
{
	char	*str;
	char	*file_content;
	char	*tmp;
	char	**graph;

	file_content = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		tmp = ft_strjoin(file_content, str);
		if (file_content != NULL)
			free(file_content);
		free(str);
		file_content = tmp;
	}
	if (file_content == NULL)
		return (NULL);
	graph = ft_split(file_content, '\n');
	if (file_content[ft_strlen(file_content) - 1] == '\n'
		|| check_nl(file_content))
		return (free(file_content), ft_printf("Error"), NULL);
	free(file_content);
	return (graph);
}
