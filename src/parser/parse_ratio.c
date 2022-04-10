#include "parser.h"

double	parse_ratio(char *ratio)
{
	double	result;

	result = ft_my_atof(ratio);
	if (result < 0 || result > 1)
		custom_exit("Ratio must be between 0 and 1");
	return (result);
}
