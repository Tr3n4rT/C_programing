/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:29:47 by mleroux           #+#    #+#             */
/*   Updated: 2022/03/08 10:07:14 by mleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	compare_a(int a, int b, int c, int *tab)
{
	if (tab[a] > tab[c])
	{
		ft_swap(&tab[a], &tab[c]);
	}
	if (tab[a] > tab[b])
	{
		ft_swap(&tab[a], &tab[b]);
	}
}

void	compare_b(int a, int b, int c, int *tab)
{
	if (tab[b] > tab[c])
	{
		ft_swap(&tab[b], &tab[c]);
	}
	if (tab[b] < tab[a])
	{
		ft_swap(&tab[b], &tab[a]);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = a + 1;
	c = size - 1;
	while (a < size - 1)
	{
		compare_a(a, b, c, tab);
		while (b < size - 1 && b < c)
		{
			compare_b(a, b, c, tab);
			b++;
		}
		a++;
		b = a + 1;
	}
}
