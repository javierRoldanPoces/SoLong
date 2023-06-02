/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:31:30 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/01 18:31:54 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	countdigit(long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count++;
		return (count);
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nlong;
	char	*s;
	int		i;

	nlong = n;
	i = countdigit(nlong);
	s = (char *)malloc(sizeof (char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	i--;
	if (nlong == 0)
		s[0] = '0';
	if (nlong < 0)
	{
		s[0] = '-';
		nlong = nlong * -1;
	}
	while (i >= 0 && nlong != 0)
	{
		s[i] = (nlong % 10) + '0';
		nlong = nlong / 10;
		i--;
	}
	return (s);
}
