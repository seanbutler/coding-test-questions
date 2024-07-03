#include <iostream>
#include <vector>

int main(int, char **)
{
    std::cout << "coin sort from leet-code-tests!\n";

    int amount = 123;
    std::vector<int> british_coins{200, 100, 50, 20, 10, 5, 2, 1};
    std::vector<int> change_given = {};

    std::cout << "checking data .... " << std::endl;
    std::cout << amount << std::endl;
    for (auto N : british_coins)
    {
        std::cout << N << ", ";
    }
    std::cout << std::endl;

    std::cout << "change .... " << std::endl;
    int count = 0;
    for (auto N : british_coins)
    {
        count = amount / N;
        std::cout << N << " " << count << std::endl;
        change_given.push_back(count);
        amount = amount - (count * N);
    }

    std::cout << "result .... " << std::endl;

    int check = 0;
    for (int n = 0; n < change_given.size(); ++n)
    {
        std::cout << british_coins[n] << " " << change_given[n] << " " << british_coins[n] * change_given[n] << std::endl;
        check += british_coins[n] * change_given[n];
    }

    std::cout << "double check .... " << std::endl;

    std::cout << check << std::endl;
    return 0;
}
