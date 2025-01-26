/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:14:43 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/25 17:04:37 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(game);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		game->mv_count += up(game);
	if (keycode == 0 || keycode == 123)
		game->mv_count += left(game);
	if (keycode == 1 || keycode == 125)
		game->mv_count += down(game);
	if (keycode == 2 || keycode == 124)
		game->mv_count += right(game);
	draw_map(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(0);
}
