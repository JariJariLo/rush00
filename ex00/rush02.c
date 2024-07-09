/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanz-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:22:02 by psanz-pa          #+#    #+#             */
/*   Updated: 2024/07/06 11:08:54 by psanz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	extremo_superior(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('A');
		else if (y != n_columnas)
			ft_putchar('B');
		else if (y == n_columnas)
			ft_putchar('A');
		y++;
	}
	ft_putchar('\n');
}

void	extremo_inferior(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('C');
		else if (y != n_columnas)
			ft_putchar('B');
		else if (y == n_columnas)
			ft_putchar('C');
		y++;
	}
}

void	cuerpo(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('B');
		else if (y != n_columnas)
			ft_putchar(' ');
		else if (y == n_columnas)
			ft_putchar('B');
		y++;
	}
}

void	error(int n_columnas, int n_filas)
{
	if (n_columnas == 0)
	{
		write(1, "¿Cómo que columnas nulas?", 24);
		ft_putchar('\n');
	}
	else if (n_filas == 0)
	{
		write(1, "¿Cómo que filas nulas?", 20);
		ft_putchar('\n');
	}
	else if ((n_filas < 0) || (n_columnas < 0))
	{
		write(1, "Pero que haces poniendo valores negativos bestia", 48);
		ft_putchar('\n');
	}
}

void	rush(int n_columnas, int n_filas)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if ((n_columnas > 0) && (n_filas > 0))
	{
		extremo_superior(n_columnas, y);
		if (n_filas > 2)
		{
			x = x + 1;
			while (++x <= n_filas)
			{
				cuerpo(n_columnas, y);
				ft_putchar('\n');
			}
		}
		if (n_filas >= 2)
		{
			extremo_inferior(n_columnas, y);
			ft_putchar('\n');
		}
	}
	else
		error(n_columnas, n_filas);
}
