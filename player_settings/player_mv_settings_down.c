/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mv_settings_down.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:30:20 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/24 17:58:15 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	basic_check_wall_down(t_game *game)
{
	if (game->map[game->player_stats.x + 1][game->player_stats.y] == WALL ||
		game->map[game->player_stats.x][game->player_stats.y] == EXIT ||
		(game->map[game->player_stats.x + 1][game->player_stats.y] == EXIT &&
		game->collect != 0) ||
		game->enemy_kill != 0)
		return (0);
	return (1);
}

void	check_empty_down(t_game *game)
{
	game->map[game->player_stats.x + 1][game->player_stats.y] = 'P';
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->player_stats.x += 1;
}

void	check_collect_down(t_game *game)
{
	game->map[game->player_stats.x + 1][game->player_stats.y] = 'P';
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->collect--;
	game->player_stats.x += 1;
}

void	check_exit_down(t_game *game)
{
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->player_stats.x += 1;
	ft_printf("You win\n");
}
