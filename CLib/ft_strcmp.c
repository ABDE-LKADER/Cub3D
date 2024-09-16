/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:39:17 by abadouab          #+#    #+#             */
/*   Updated: 2023/12/07 21:15:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CLib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
		(TRUE) && (s1++, s2++);
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
