/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:18:12 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/21 13:19:53 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_len_i(t_map *map)
{
	size_t	j;
	size_t	len_j;
	size_t	len_i;

	j = 0;
	len_j = ft_strleen(map->mini_map);
	len_i = ft_strlenn(map->mini_map);
	while (j < len_j)
	{
		if (map->mini_map[len_i - 1][j] != '1' && map->mini_map[len_i
			- 1][j] != ' ')
		{
			printf("ERROR :len_i --- map must be closed by walls ! \n");
			exit(1);
		}
		j++;
	}
}

void	check_len_j(t_map *map)
{
	size_t	i;
	size_t	len_j;
	size_t	len_i;

	i = 0;
	len_j = ft_strleen(map->mini_map) - 1;
	len_i = ft_strlenn(map->mini_map) - 1;
	while (i < len_i)
	{
		len_j = ft_strleen(map->mini_map) - 1;
		while (map->mini_map[i][len_j] == ' '
			|| map->mini_map[i][len_j] == '\t')
			len_j--;
		if (map->mini_map[i][len_j] != '1')
		{
			printf("ERROR :len_j --- map must be closed by walls ! \n");
			exit(1);
		}
		i++;
	}
}
