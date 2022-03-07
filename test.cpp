#include <gtest/gtest.h>
#include "main.h"

TEST(testCase, StrLessSort)
{
    std::string number = 23145;
    EXPECT_STREQ(12345, StrLessSort(number));
}

TEST(testCase, StrReverse)
{
    std::string number = 23145;
    EXPECT_STREQ(54132, StrLessSort(number));
}