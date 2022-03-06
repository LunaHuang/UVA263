#include <gtest/gtest.h>
#include "main.h"

TEST(testCase, test0)
{
    int number = 45321;
    std::vector< unsigned int > v = NumberSplit(number);
    for (int i; i < v.size(); i++) {
        int mod = number % (i * 10);
        EXPECT_EQ(v[i], mod);
        std::string s = std::to_string(mod);
        EXPECT_STREQ("mod : %d", s.c_str());
    }
}

TEST(testCase, test1)
{
    static const int arr[] = { 3, 2, 4, 5, 6, 3 };
    std::vector< unsigned int > v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    EXPECT_EQ(HLBubbleSort(v), 233456);
}

TEST(testCase, test2)
{
    static const int arr[] = { 3, 2, 4, 5, 6, 3 };
    std::vector< unsigned int > v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    EXPECT_EQ(LHBubbleSort(v), 654332);
    //    EXPECT_EQ(HBubbleSort(v),564332); // fail test
}

TEST(testCase, test3)
{
    static const int arr[] = { 1, 2, 3, 4, 5, 6 };
    std::vector< unsigned int > v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    EXPECT_EQ(ReverseOrder(v), 123456);
}
