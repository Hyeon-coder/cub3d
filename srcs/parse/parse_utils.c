/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:47 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/11/19 15:26:09 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\n' || line[i] == '\0');
}

int	find_player(t_map_config *config)
{
	int	y;
	int	x;

	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map_grid[y][x])
		{
			if (ft_strchr("NSEW", config->map_grid[y][x]))
			{
				if (config->start_dir != '\0')
					return (ft_perror(ERRMSG_FINDPLAYER));
				config->start_dir = config->map_grid[y][x];
				config->start_pos.x = (double)x + 0.5;
				config->start_pos.y = (double)y + 0.5;
				config->map_grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (config->start_dir == '\0')
		return (ft_perror("Error: No player found in map\n"));
	return (0);
}
