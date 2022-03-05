#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>
#include <math.h>

#ifdef TEST_CASE
#include <gtest/gtest.h>
#endif
std::vector<int> NumberSplit(int number)
{
	std::vector<int> vSplit;
	for(; number; number/=10)
		vSplit.push_back( number % 10 );
    return vSplit;
}

int HBubbleSort(std::vector<int> array)
{
	int size = array.size();
    int number = 0;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
    }

    for(int i = 0; i < size; i++){
//		std::cout << "number " << i << " " << array[i] << " ";
		number = number + array[i] * pow(10, i);
//		std::cout << "\n number : " << number <<std::endl;
    }
    
    return number;
}

int LBubbleSort(std::vector<int> array)
{
	int size = array.size();
    int number = 0;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j)
            if (array[j] < array[j + 1])
                std::swap(array[j], array[j + 1]);
    }

    for(int i = size - 1; i >= 0; --i){
//		std::cout << "number " << i << " " << array[i] << " ";
		number = number + array[i] * pow(10, i);
//		std::cout << "\n number : " << number <<std::endl;
    }
    
    return number;
}

bool CheckNumber(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (std::isdigit(str[i]) == false)
			return false;
    }
	return true;
}

static int chain = 0;
static std::vector<int> leaves;
static void TestFunction(int max, int min)
{
    int leave, size;
    int b_val = max;
    int l_val = min;

    leave = b_val - l_val;
    chain ++;
	std::cout << b_val << " - " << l_val << " = " << leave << std::endl;
    size = leaves.size();
/*
    std::cout << "leaves size: " << size << std::endl;
    for(int i=0; i< size; i++)
		std::cout << " " << leaves[i] << " ";
	std::cout << std::endl;
*/
    if(size != 0){
        for(int i=0; i< size; i++){
			if(leaves[i] == leave)
				return;
        }
	}
    leaves.push_back(leave);
    std::vector<int> r_v = NumberSplit(leave);
    TestFunction(HBubbleSort(r_v), LBubbleSort(r_v));

}

#ifdef TEST_CASE
TEST(testCase, test0){
    int number = 45321;
    std::vector<int> v = NumberSplit(number);
    for(int i; i < v.size(); i++){
       int mod = number % (i * 10);
       EXPECT_EQ(v[i],mod);
       std::string s = std::to_string(mod);
       EXPECT_STREQ("mod : %d", s.c_str());
    }
}

TEST(testCase, test1){
	static const int arr[] = {3,2,4,5,6,3};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    EXPECT_EQ(LBubbleSort(v),233456);
}

TEST(testCase, test2){
	static const int arr[] = {3,2,4,5,6,3};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    EXPECT_EQ(HBubbleSort(v),654332);
//    EXPECT_EQ(HBubbleSort(v),564332); // fail test
}
#endif

static int input_number = 0;
int main(int argc, char **argv) {
/*
    if( argc != 2) {
		std::cout << "Please input one number " << std::endl;
		return false;
    }
    if( CheckNumber(argv[1]) == false){
		std::cout << "Incorrect input, please input number " << std::endl;
		return false;
	}
    int input_number = atoi(argv[1]);
*/

#ifndef TEST_CASE
    while( std::cin >> input_number ){
	    std::cout << std::endl;
        std::cout << "Original number was " << input_number <<std::endl;
        std::vector<int> r_v = NumberSplit(input_number);
        TestFunction(HBubbleSort(r_v), LBubbleSort(r_v));
        std::cout << "Chain length " << chain << std::endl;
        chain = 0;
        input_number = 0;
        leaves.clear();
	}
#else
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
#endif
    return 0;
}

