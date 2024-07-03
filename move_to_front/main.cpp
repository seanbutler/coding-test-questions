#include <iostream>
#include <array>
#include <limits>

const int NUM_VALS = 10;

bool swap(std::array<int, NUM_VALS> &data, int index1, int index2)
{
    if (index1 < 0)
        return false;

    if (index2 < 0)
        return false;

    if (index1 >= data.size())
        return false;

    if (index2 >= data.size())
        return false;

    int tmp;
    tmp = data[index1];
    data[index1] = data[index2];
    data[index2] = tmp;

    return true;
}

int main(int, char **)
{
    std::cout << "move to front leet-code-tests!\n";

    const int special = 18;
    std::array<int, NUM_VALS> input_data = {0, 6, 1, 4, 18, 8, 2, 18, 1, 7};

    int index_slow = 0;
    for (int index_fast = 0; index_fast < input_data.size(); ++index_fast)
    {
        if (input_data[index_fast] == special)
        {
            swap(input_data, index_fast, index_slow);
            ++index_slow;
        }
    }

    for (auto N : input_data)
    {
        std::cout << N << " ";
    }
    std::cout << std::endl;

    return 0;
}
