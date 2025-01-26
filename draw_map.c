/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:58:08 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/25 12:33:21 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game *game)
{
	int	riga;
	int	colonna;

	riga = 0;
	colonna = 0;
	check_img(game);
	while (game->map[riga])
	{
		colonna = 0;
		while (game->map[riga][colonna])
		{
			set_wcp(game, riga, colonna);
			set_eenem(game, riga, colonna);
			colonna++;
		}
		riga++;
	}
	game->no_collect = 1;
	display_moves(game);
	return (0);
}
