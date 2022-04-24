#include "test_helper.hpp"
#include <algorithm>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>

extern "C"
{
#include "libft.h"
#include "parser.h"
}

int g_OK;

void atof_test(const char *s)
{
	bool flag = false;
	double d = strtod(s, NULL);
	double d2 = ft_my_atof(s, &flag);
	EXPECT_EQ(flag, g_OK);
	if (flag)
    {
		EXPECT_DOUBLE_EQ(d, d2);
    }
}

TEST(Libft, FtAtof)
{
	g_OK = true;
	atof_test("3.3");
	atof_test("-3.3");
	atof_test("-53.3");
	atof_test("123456");
	atof_test("0");
	atof_test("1");
	atof_test("100");
	atof_test("12345");
	atof_test("1.1");
	atof_test("0.1");
	atof_test("0.01");
	atof_test("-0.01");
	atof_test("-1.01");
	atof_test("-100.01");
	atof_test("-100");
	char buf[100];
	sprintf(buf, "%d", INT_MAX);
	// printf("%d\n", INT_MAX);
	atof_test(buf);
	sprintf(buf, "%d", INT_MIN);
	atof_test(buf);
	// printf("%d\n", INT_MIN);
	atof_test("0.0");
}

TEST(Libft, FtAtofError)
{
	g_OK = false;
	atof_test("01");
	atof_test("001");
	atof_test("1.");
	atof_test("1..");
	atof_test("0.");
	atof_test("1a");
	atof_test("a1");
	atof_test("1.a");
	atof_test("1.1a");
	atof_test("1.1a1");
	atof_test("1.a.1");
	atof_test("1...1");
	atof_test("1...1.");
	atof_test(".");
	char buf[2000];
	buf[0] = '9';
	atof_test(buf);
	atof_test("-");
	atof_test("+");
	atof_test("...");
	atof_test("00");
	atof_test("");
	atof_test("-00");
	atof_test("-.");
	atof_test("-.1");
	atof_test("-1.");
	atof_test(".1");
	atof_test(".1a");
	atof_test(".a1");
	atof_test("-a");
	atof_test("+a");
	atof_test("1.1.");
	atof_test("1.1.1");
	atof_test("1-");
	atof_test("--1");
	atof_test("-+1");
	atof_test("+-1");
	atof_test("1..1");
	atof_test("--");
	atof_test("++");
	atof_test("\"");
	atof_test("\'");
	atof_test("..");
	// atof_test(NULL);
}
