#include <iostream>
#include <array>
#include <limits>

int main(int, char **)
{
    std::cout << "min max sum from leet-code-tests!\n";

    const int amount = 123;
    const int NUM_VALS = 10;
    const std::array<int, NUM_VALS> input_data = {0, 6, 1, 4, 18, 8, 2, 18, 1, 7};

    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    int sum = 0;

    for (int n = 0; n < input_data.size(); ++n)
    {
        if (input_data[n] < min)
        {
            min = input_data[n];
        }
        
        if (input_data[n] > max)
        {
            max = input_data[n];
        }
    }
    sum = min + max;

    return sum;
}
