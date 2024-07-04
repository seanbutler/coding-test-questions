#include <iostream>
#include <list>

// https://www.hackerrank.com/blog/coding-interview-questions-programmers-should-know/

/*

The janitor of a high school is extremely efficient. By the end of each day, all of the
school’s waste is in plastic bags weighing between 1.01 pounds and 3.00 pounds. All
plastic bags are then taken to the trash bins outside. One trip is described as selecting
a number of bags which together do not weigh more than 3.00 pounds, dumping them in the
outside trash can and returning to the school. Given the number of plastic bags, and the
weights of each bag, determine the minimum number of trips the janitor has to make.

*/

#define MAX 25

void dump(std::list<int> list)
{
    for (auto B : list)
    {
        std::cout << B << " ";
    }
    std::cout << std::endl;
}

int main(int, char **)
{
    std::cout << "efficient leet-code-tests!\n";

    std::list<int> bags;
    std::list<int> carried;

    srand(time(nullptr));
    // srand(1);

    int m = rand() % MAX;
    for (int n = 0; n < m; ++n)
    {
        bags.emplace_back(1 + (rand() % (MAX - 1)));
    }
    dump(bags);

    bags.sort(std::greater<int>());
    dump(bags);

    int trips = 0;
    int carried_total;

    while (bags.begin() != bags.end())
    {
        carried_total = 0;
        carried.clear();

        // get the front therefore largest
        std::list<int>::iterator itor1 = bags.begin();
        carried.push_back(*itor1);
        carried_total += *itor1;

        // search through till we find one sized to fill whats left in carried
        std::list<int>::iterator itor2 = bags.begin();
        bags.erase(itor2);

        std::list<int>::iterator itor3 = bags.begin();
        while ((itor3 != bags.end()) && (*itor3 > MAX - carried_total))
        {
            itor3++;
        }

        if (itor3 != bags.end())
        {
            carried.push_back(*itor3);
            bags.erase(itor3);
            carried_total += *itor3;
        }

        dump(carried);
        std::cout << trips << " " << carried_total << std::endl;
        trips++;
    }

    dump(bags);
    dump(carried);

    std::cout << trips << std::endl;
    return 0;
}
