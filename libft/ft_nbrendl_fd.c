/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:27:18 by agabrie           #+#    #+#             */
/*   Updated: 2018/07/20 08:28:04 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_nbrendl_fd(int nbr, int fd)
{
	ft_putnbr_fd(nbr, fd);
	ft_putchar_fd('\n', fd);
}