/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:52:17 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/25 12:23:01 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wcp(t_game *game, int riga, int colonna)
{
	if (game->map[riga][colonna] == WALL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			colonna * 64, riga * 64);
	}
	if (game->map[riga][colonna] == EMPTY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_0,
			colonna * 64, riga * 64);
	}
	if (game->map[riga][colonna] == PLAYER)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			colonna * 64, riga * 64);
		game->player_stats.x = riga;
		game->player_stats.y = colonna;
	}
	if (game->map[riga][colonna] == COLLECTIBLE)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
			colonna * 64, riga * 64);
	}
}

void	set_eenem(t_game *game, int riga, int colonna)
{
	if (game->map[riga][colonna] == EXIT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			colonna * 64, riga * 64);
	}
	if (game->map[riga][colonna] == ENEMY_S)
	{
		game->enemy.x = riga;
		game->enemy.y = colonna;
		game->enemy_num++;
	}
}
