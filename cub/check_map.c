/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:39 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/25 11:14:18 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_player(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j])
		{
			if (map->mini_map[i][j] == 'N' || map->mini_map[i][j] == 'E'
				|| map->mini_map[i][j] == 'W' || map->mini_map[i][j] == 'S')
			{
				k++;
			}
			j++;
		}
		i++;
	}
	if (k > 1 || k == 0)
		error_print("ERROR : the player position ! \n");
}

void	check_allmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j])
		{
			if (map->mini_map[i][j] != '1' && map->mini_map[i][j] != '0'
				&& map->mini_map[i][j] != 'E' && map->mini_map[i][j] != 'S'
				&& map->mini_map[i][j] != 'N' && map->mini_map[i][j] != 'W'
				&& map->mini_map[i][j] != ' ' && map->mini_map[i][j] != '\t')
			{
				printf("ERROR : map should have just 6 elements \n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	map->fmap = NULL;
	map->fmap = ft_split(map->ptr, '\n');
	check_texture(map);
	check_colors(map);
	error_colors(map);
	map_pointer(map);
	check_map_length(map);
	check_walls(map);
	check_allmap(map);
	check_player(map);
	check_space_errors(map);
}
