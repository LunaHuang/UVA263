#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>
#include <math.h>

#ifdef WITH_GTEST
#include <gtest/gtest.h>
#endif

std::string StrLessSort(std::string input)
{
    std::string input_str = input;
    std::sort(input_str.begin(), input_str.end(), std::less<char>());
    return input_str;
}

std::string StrReverse(std::string input)
{
    std::string str = input;
    std::reverse(str.begin(), str.end());
    return str;
}

static unsigned int chain = 0;
static std::vector< unsigned int > leaves;

static void NumberChain(std::string number)
{
    unsigned int leave, size;
    unsigned int b_val = 0;
    unsigned int l_val = 0;
    std::string min_nu;
    std::string max_nu;

    min_nu.clear();
    max_nu.clear();
    min_nu = StrLessSort(number);
    l_val = std::stoul (min_nu,nullptr,10);
    max_nu = StrReverse(min_nu);
    b_val = std::stoul (max_nu,nullptr,10);

    leave = b_val - l_val;
    chain++;
    std::cout << b_val << " - " << l_val << " = " << leave << std::endl;
    size = leaves.size();
    if (size != 0) {
        for (unsigned int i = 0; i < size; i++) {
            if (leaves[i] == leave)
                return;
        }
    }
    leaves.push_back(leave);
    std::string r_v = std::to_string(leave);
    NumberChain(r_v);
}

int main(int argc, char **argv)
{
    std::string input_number;
    
#ifdef WITH_GTEST
    int ret;
    testing::InitGoogleTest(&argc, argv);
    ret = RUN_ALL_TESTS();
#endif
    while (std::cin >> input_number) {
        if (std::stoul(input_number) == 0) {
            return 0;
        }
        std::cout << "Original number was " << input_number << std::endl;
        NumberChain(input_number);
        std::cout << "Chain length " << chain << std::endl;
        std::cout << std::endl;
        chain = 0;
        input_number.clear();
        leaves.clear();
    }
    return 0;
}
