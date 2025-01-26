/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mv_settings_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:22:43 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/24 17:58:07 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	basic_check_wall_right(t_game *game)
{
	if (game->map[game->player_stats.x][game->player_stats.y + 1] == WALL ||
		game->map[game->player_stats.x][game->player_stats.y] == EXIT ||
		(game->map[game->player_stats.x][game->player_stats.y + 1] == EXIT &&
		game->collect != 0) ||
		game->enemy_kill != 0)
		return (0);
	return (1);
}

void	check_empty_right(t_game *game)
{
	game->map[game->player_stats.x][game->player_stats.y + 1] = 'P';
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->player_stats.y += 1;
}

void	check_collect_right(t_game *game)
{
	game->map[game->player_stats.x][game->player_stats.y + 1] = 'P';
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->collect--;
	game->player_stats.y += 1;
}

void	check_exit_right(t_game *game)
{
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	ft_printf("You win\n");
}
