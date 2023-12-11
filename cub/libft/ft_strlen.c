/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:59:51 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/11/01 17:32:26 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
size_t	ft_strlen(const char *str)

{
	size_t	i;
	if(!str)
	{
		printf("kkk\n");
		return(0);
	}
		

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
