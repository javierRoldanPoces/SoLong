/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:39:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/08 19:45:44 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// controlar muros a 1 , sea un rectangulo , almenos una E , almenos una C
int	map_valid(t_so_long *c)
{
	int	i;

	i = 0;
	if (c->h == c->w)
	{
		write(1, "error", 5);
		return (-1);
	}
	return (0);
}
