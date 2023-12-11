/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:38 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/11/01 17:40:46 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_print(char *str)
{
	printf("%s", str);
	exit(1);
}

void	valid_texture(t_map *map)
{
	if (ft_strncmp(map->texture[0], "NO", 2) != 0)
		error_print("ERROR : invalid texture  \n");
	if (ft_strncmp(map->texture[2], "SO", 2) != 0)
		error_print("ERROR : invalid texture  \n");
	if (ft_strncmp(map->texture[4], "WE", 2) != 0)
		error_print("ERROR : invalid texture  \n");
	if (ft_strncmp(map->texture[6], "EA", 2) != 0)
		error_print("ERROR : invalid texture  \n");
}

void	check_texture(t_map *map)
{
	int		i;
	char	*text;
	char	*tmp;

	i = 0;
	map->texture = NULL;
	text = NULL;
	while (i < 4)
	{
		
		text = ft_joinstr(text, map->fmap[i]);
		tmp = text;
		i++;
	}
	map->texture = ft_split(text, ' ');
	valid_texture(map);
}

int	find_first_map(char **fmap)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (fmap[i++])
	{
		while (fmap[i][j] == ' ' || fmap[i][j] == '\t' || fmap[i][j] == '1'
			|| fmap[i][j] == '0')
		{
			if (fmap[i][j] == '1')
			{
				k = 1;
				break ;
			}
			else if (fmap[i][j] == '0')
				error_print("ERROR: first element should be '1'\n");
			j++;
		}
		if (k == 1)
			break ;
	}
	return (i);
}

void	map_pointer(t_map *map)
{
	int		i;
	char	*j_map;
	char	*tmp;

	j_map = NULL;
	i = find_first_map(map->fmap);
	while (map->fmap[i])
	{
		tmp = ft_join(j_map, map->fmap[i]);
		free(j_map);
		j_map = tmp;
		i++;
	}
	map->mini_map = ft_split(j_map, 'h');
	free(j_map);
}
