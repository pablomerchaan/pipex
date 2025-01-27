/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:32:54 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/10 14:18:51 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (str == 0)
		return (ft_putstr("(null)"));
	while (str[c] != '\0')
	{
		write (1, &str[c], 1);
		c++;
	}
	return (c);
}
