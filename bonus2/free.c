/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfevrier <tfevrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:24:55 by tfevrier          #+#    #+#             */
/*   Updated: 2019/12/04 15:24:56 by tfevrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_menu(t_menu *menu)
{
	int		i;

	i = 0;
	while (i < menu->nb_levels)
		free(menu->levels[i++]);
	free(menu->levels);
	mlx_destroy_window(menu->mlx.ptr, menu->mlx.win);
	free(menu);
}

void	free_textures(t_world *world)
{
	t_side	side;

	side = N;
	while (side < E)
	{
		if (world->textures[side].data)
			mlx_destroy_image(world->mlx.ptr, world->textures[side].ptr);
		side++;
	}
}

void	free_map(t_world *world)
{
	int		i;

	if (world->map)
	{
		i = 0;
		while (i < world->map_height)
			free(world->map[i++]);
		free(world->map);
	}
}

void	free_world(t_world *world)
{
	if (world->sprites)
		free(world->sprites);
	if (world->depth_buffer)
		free(world->depth_buffer);
	if (world->music_file)
		free(world->music_file);
	if (world->screen.data)
		mlx_destroy_image(world->mlx.ptr, world->screen.ptr);
	if (world->texture_sprite.data)
		mlx_destroy_image(world->mlx.ptr, world->texture_sprite.ptr);
	if (world->textures_gun[0].data)
		mlx_destroy_image(world->mlx.ptr, world->textures_gun[0].ptr);
	if (world->textures_gun[1].data)
		mlx_destroy_image(world->mlx.ptr, world->textures_gun[1].ptr);
	free_textures(world);
	free_map(world);
	if (world->mlx.win)
		mlx_destroy_window(world->mlx.ptr, world->mlx.win);
	free(world);
	system("killall afplay");
}
