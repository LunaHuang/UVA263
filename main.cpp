#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>
#include <math.h>

#ifdef WITH_GTEST
#include <gtest/gtest.h>
#endif
std::vector< unsigned int > NumberSplit(unsigned int number)
{
    std::vector< unsigned int > vSplit;
    for (; number; number /= 10)
        vSplit.push_back(number % 10);
    return vSplit;
}

int LHBubbleSort(std::vector< unsigned int > array)
{
    int size = array.size();
    int number = 0;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
    }
    for (int i = 0; i < size; i++) {
        number = number + array[i] * pow(10, i);
    }
    return number;
}

int HLBubbleSort(std::vector< unsigned int > array)
{
    int size = array.size();
    int number = 0;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j)
            if (array[j] < array[j + 1])
                std::swap(array[j], array[j + 1]);
    }
    for (int i = size - 1; i >= 0; --i) {
        number = number + array[i] * pow(10, i);
    }
    return number;
}

int ReverseOrder(std::vector< unsigned int > array)
{
    int size = array.size();
    int number = 0;
    for (int i = 0; i < size / 2; i++) {
        std::swap(array[i], array[size - 1 - i]);
    }
    for (int i = 0; i < size; i++) {
        number = number + array[i] * pow(10, i);
    }
    return number;
}

bool CheckNumber(std::string str)
{
    for (int i = 0; i < str.length(); i++) {
        if (std::isdigit(str[i]) == false)
            return false;
    }
    return true;
}

static unsigned int chain = 0;
static std::vector< unsigned int > leaves;
static void NumberChain_2(unsigned int max, unsigned int min)
{
    unsigned int leave, size;
    unsigned int b_val = max;
    unsigned int l_val = min;

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
    std::vector< unsigned int > r_v = NumberSplit(leave);
    NumberChain_2(LHBubbleSort(r_v), HLBubbleSort(r_v));
}

static void NumberChain(std::vector< unsigned int > number)
{
    unsigned int leave, size;
    unsigned int b_val;
    unsigned int l_val;

    b_val = LHBubbleSort(number);
    std::vector< unsigned int > r_v = NumberSplit(b_val);
    l_val = ReverseOrder(r_v);
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
    r_v = NumberSplit(leave);
    NumberChain(r_v);
}

static int input_number = 0;
int main(int argc, char **argv)
{

#ifdef WITH_GTEST
    int ret;
    testing::InitGoogleTest(&argc, argv);
    ret = RUN_ALL_TESTS();
#endif
    while (std::cin >> input_number) {
        if (input_number == 0) {
            break;
        }
        std::cout << "Original number was " << input_number << std::endl;
        std::vector< unsigned int > r_v = NumberSplit(input_number);
        //NumberChain_2(LHBubbleSort(r_v), HLBubbleSort(r_v));
        NumberChain(r_v);
        std::cout << "Chain length " << chain << std::endl;
        std::cout << std::endl;
        chain = 0;
        input_number = 0;
        leaves.clear();
    }
    return 0;
}
