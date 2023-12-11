/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:37:24 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/11/01 17:40:07 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	function_norm(t_map *map, int i, int j)
{
	if (map->mini_map[i + 1] && map->mini_map[i + 1][j] != ' '
		&& map->mini_map[i + 1][j] != '1')
		error_print("ERROR : spaces \n");
	if (i > 0 && map->mini_map[i - 1] && map->mini_map[i - 1] && map->mini_map[i
			- 1][j] != ' ' && map->mini_map[i - 1][j] != '1')
		error_print("ERROR : spaces \n");
}

void	check_space_errors(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j])
		{
			if (map->mini_map[i][j] == ' ')
			{
				if (map->mini_map[i][j + 1] && map->mini_map[i][j + 1] != ' '
					&& map->mini_map[i][j + 1] != '1')
					error_print("ERROR : spaces \n");
				if (j > 0 && map->mini_map[i][j - 1] && map->mini_map[i][j
					- 1] != ' ' && map->mini_map[i][j - 1] != '1')
					error_print("ERROR : spaces \n");
				function_norm(map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_colors(t_map *map)
{
	int		i;
	int		j;
	char	*col;
	char	*tmp;

	i = 0;
	j = 0;
	col = NULL;
	while (map->fmap[i])
	{
		if (map->fmap[i][j] == 'F' && map->fmap[i + 1][j] == 'C')
		{
			col = ft_joinstr(col, map->fmap[i]);
			tmp = col;
			//free(col);
			col = ft_joinstr(col, map->fmap[i + 1]);
		}
		i++;
	}
	if (col == NULL)
		printf("error colors  ! \n");
	map->colors = ft_split(col, ' ');
	free(col);
}
