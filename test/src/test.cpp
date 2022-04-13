#include <algorithm>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include "test_helper.hpp"
#include <gtest/gtest.h>

extern "C"
{
#include "libft.h"
#include "parser.h"
}

TEST(Libft, FtAtof) {
    EXPECT_EQ(ft_my_atof("3.3"), 3.3);
    EXPECT_EQ(ft_my_atof("-3.3"), -3.3);
    EXPECT_EQ(ft_my_atof("-53.3"), -53.3);
    EXPECT_EQ(ft_my_atof("123456"), 123456);
}
