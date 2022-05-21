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

void	register_hooks(t_mlx *mlx_config)
{
	mlx_hook(mlx_config->win_ptr, ClientMessage, StructureNotifyMask, my_exit,
			NULL);
	mlx_key_hook(mlx_config->win_ptr, key_hook, NULL);
}
