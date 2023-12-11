/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:09:20 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/25 11:28:52 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_i(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j] == ' ' || map->mini_map[i][j] == '\t')
			j++;
		if (map->mini_map[i][j] != '1')
		{
			printf("ERROR : i -- map must be closed by walls ! \n");
			exit(1);
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->mini_map[i][j])
	{
		if (map->mini_map[i][j] != '1' && map->mini_map[i][j] != ' ')
		{
			printf("ERROR :j -- la carte n'est pas entouree par des murs!");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	check_i(map);
	check_len_i(map);
	check_len_j(map);
}

size_t	ft_strleen(char **ptr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (ptr[i][j])
	{
		j++;
	}
	return (j);
}

size_t	ft_strlenn(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i++;
	}
	return (i);
}
