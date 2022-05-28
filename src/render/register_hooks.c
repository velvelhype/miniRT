/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:50 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:32:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "keys.h"
#include "mlx.h"

static int	my_exit(void)
{
	exit(0);
}

static int	key_hook(int key_code, void *p)
{
	(void)p;
	if (key_code == ESCAPE || key_code == KEY_Q)
	{
		return (my_exit());
	}
	return (0);
}

void	register_hooks(t_mlx *m)
{
	mlx_hook(m->win_ptr, ClientMessage, StructureNotifyMask, my_exit, NULL);
	mlx_key_hook(m->win_ptr, key_hook, NULL);
}
