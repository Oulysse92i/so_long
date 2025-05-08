/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:11:04 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/20 18:41:53 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (str + ft_strlen(str));
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("ft_strchr : %s\n", ft_strchr(av[1], atoi(av[2])));
	printf("   strchr :%s\n", strchr(av[1], atoi(av[2])));
	return (0);
}
*/