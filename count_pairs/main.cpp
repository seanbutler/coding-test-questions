#include <iostream>

int diff(int first, int second)
{
    return abs(first - second);
}

int count_pairs_with_difference(int K, int D, int *nums)
{
    int counter = 0;
    for (int first = 0; first < K - 1; ++first)
    {
        for (int second = first + 1; second < K; ++second)
        {
            if (diff(nums[first], nums[second]) == D)
            {
                ++counter;
            }
        }
    }
    return counter;
}

int main(int, char **)
{
    std::cout << "count the pairs!\n";

    const int K = 5;
    int D = 2;
    int numbers[K] = {1, 2, 3, 4, 5};

    std::cout << count_pairs_with_difference(K, D, numbers);

    return 0;
}
