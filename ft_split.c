/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:10:10 by vruiz-ru          #+#    #+#             */
/*   Updated: 2024/11/26 19:11:18 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	liberate(char **matriz, int nstr)
{
	while (nstr-- > 0)
	{
		free(matriz[nstr]);
	}
	free(matriz);
}

static char	**ft_split2(char const *s, char c, char	**matriz, size_t len)
{
	size_t	cont;
	size_t	checkpoint;
	int		nstr;

	cont = 0;
	nstr = 1;
	checkpoint = 0;
	while (cont < len)
	{
		if (s[cont] != c)
		{
			checkpoint = cont;
			while (s[cont] != c && s[cont] != 0)
				cont++;
			matriz[nstr] = ft_substr(s, checkpoint, cont - checkpoint);
			if (matriz[nstr++] == 0)
			{
				liberate(matriz, nstr - 1);
				return (0);
			}
		}
		cont++;
	}
	matriz[nstr] = 0;
	return (matriz);
}

static int	ft_strwords(char const *s, char c)
{
	int	cont;
	int	palabras;
	int	len;

	len = ft_strlen(s);
	palabras = 0;
	cont = 1;
	if (s[0] != c && s[0] != 0)
		palabras++;
	while (cont < len)
	{
		if (s[cont] != c && s[cont - 1] == c)
			palabras++;
		cont++;
	}
	return (palabras);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	size_t	len;
	int		i;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	matriz = malloc((ft_strwords(s, c) + 2) * sizeof(char *));
	if (matriz)
	{
		matriz[i] = malloc(sizeof(char));
		if (matriz[i] == NULL)
			return (NULL);
		*matriz[i] = '\0';
		return (ft_split2(s, c, matriz, len));
	}
	return (0);
}
