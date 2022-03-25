#include "miniRT.h"

void	draw(t_rt *rt_info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < rt_info->width_max)
	{
		while (x < rt_info->height_max)
		{
			// colide_detection();
			// shading();
			// lighting();
			x++;
		}
		x = 0;
		y++;
	}
}