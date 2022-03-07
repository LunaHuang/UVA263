#include <gtest/gtest.h>
#include <string>
#include "main.h"

TEST(testCase, StrLessSort)
{
    std::string number = std::to_string(23145);
    EXPECT_STREQ("12345", StrLessSort(number).c_str());
}

TEST(testCase, StrReverse)
{
    std::string number = std::to_string(23145);
    EXPECT_STREQ("54132", StrReverse(number).c_str());
}
