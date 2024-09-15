/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:52:14 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/23 10:05:10 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CLib.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + 1;
	str = allocate(len, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memcpy(str, s1, ft_strlen(s1) + 1), str);
}
