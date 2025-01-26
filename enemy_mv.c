/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:12:08 by ftroise           #+#    #+#             */
/*   Updated: 2023/05/25 17:17:05 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontal(t_game *game)
{
	static int	time;

	if (time == 25)
	{
		check_movement_enemyh_plus(game);
		check_movement_enemyh_minus(game);
		time = 0;
	}
	time++;
	draw_map(game);
	return (0);
}
