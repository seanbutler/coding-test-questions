#include <iostream>
#include <vector>
#include <array>
#include <cstddef>

namespace hashtable
{

    class item
    {
    public:
        item(std::string K="dummy", int V=0) : key(K), value(V) {}
        std::string key;
        int value;
    };




    u_int32_t jenkins_hash(std::string key)
    {
        // https://en.wikipedia.org/wiki/Jenkins_hash_function

        size_t i = 0;
        u_int32_t hash = 0;

        while (i != key.length() - 1)
        {
            hash += (u_int8_t)key[i++];
            hash += hash << 10;
            hash ^= hash >> 6;
        }
        hash += hash << 3;
        hash ^= hash >> 11;
        hash += hash << 15;

        return hash;
    }


    class container
    {
    public:
        container() 
        : num_items(0)
        , capacity(CAPACITY)
        , items{}
        {

        }

        void add(item & I) {
            if (items[jenkins_hash(I.key) % CAPACITY].key == "dummy") {
                items[jenkins_hash(I.key) % CAPACITY] = I;
            }
            else
            {
                
            }
        }

        static const std::size_t CAPACITY = 256;

        std::size_t num_items;
        std::size_t capacity;
        std::array<item, CAPACITY> items;
    };


}

int main(int, char **)
{
    std::cout << "hash table version 2!\n";

    hashtable::container hash_table_container;

    hash_table_container.add(item("sean", 100));
    hash_table_container.add(item("mary", 200));
    hash_table_container.add(item("henry", 300));
    hash_table_container.add(item("meadow", 400));

    return 0;
}
