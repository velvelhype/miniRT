#include "parser.h"

double	parse_ratio(char *ratio)
{
	double	result;
	bool	flag;

	result = ft_my_atof(ratio, &flag);
	if (!flag)
		custom_exit("Ratio: invalid value");
	if (result < 0 || result > 1)
		custom_exit("Ratio must be between 0 and 1");
	return (result);
}
