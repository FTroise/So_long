/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:04:41 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/25 17:14:01 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_death(t_game *game)
{
	ft_printf("GAME OVER\n");
	game->map[game->player_stats.x][game->player_stats.y] = '0';
	game->enemy_kill = 1;
}

void	checker_n_tile(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == EMPTY)
				game->tile.empty++;
			if (game->map[i][j] == EXIT)
				game->tile.e++;
			if (game->map[i][j] == COLLECTIBLE)
				game->tile.c++;
			if (game->map[i][j] == PLAYER)
				game->tile.p++;
			j++;
		}
		i++;
	}
}

void	check_movement_enemyh_plus(t_game *game)
{
	if (game->enemy.mv == 0)
	{
		if ((game->map[game->enemy.x][game->enemy.y + 1] != WALL
			|| game->map[game->enemy.x][game->enemy.y + 1] != EXIT
			|| game->map[game->enemy.x][game->enemy.y + 1] != COLLECTIBLE)
			&& (game->map[game->enemy.x][game->enemy.y + 1] == EMPTY))
		{
			game->map[game->enemy.x][game->enemy.y + 1] = 'S';
			game->map[game->enemy.x][game->enemy.y] = '0';
			game->enemy.y++;
		}
		else if (game->map[game->enemy.x][game->enemy.y + 1] == PLAYER)
		{
			game->map[game->enemy.x][game->enemy.y] = 'S';
			game->map[game->enemy.x][game->enemy.y + 1] = '0';
			game->enemy.y--;
			check_death(game);
		}
		else
			game->enemy.mv = 1;
	}
}

void	check_movement_enemyh_minus(t_game *game)
{
	if (game->enemy.mv == 1)
	{
		if ((game->map[game->enemy.x][game->enemy.y - 1] != WALL
			|| game->map[game->enemy.x][game->enemy.y - 1] != EXIT
			|| game->map[game->enemy.x][game->enemy.y - 1] != COLLECTIBLE)
			&& (game->map[game->enemy.x][game->enemy.y - 1] == EMPTY))
		{
			game->map[game->enemy.x][game->enemy.y - 1] = 'S';
			game->map[game->enemy.x][game->enemy.y] = '0';
			game->enemy.y--;
		}
		else if (game->map[game->enemy.x][game->enemy.y - 1] == PLAYER)
		{
			game->map[game->enemy.x][game->enemy.y] = 'S';
			game->map[game->enemy.x][game->enemy.y - 1] = '0';
			game->enemy.y--;
			check_death(game);
		}
		else
			game->enemy.mv = 0;
	}
}

void	check_not_tile(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != EMPTY && game->map[i][j] != PLAYER
				&& game->map[i][j] != EXIT && game->map[i][j] != COLLECTIBLE
				&& game->map[i][j] != ENEMY_S && game->map[i][j] != WALL)
			{
				ft_printf("Error\n you set a tile that is not correct\n");
				free_map(game);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
