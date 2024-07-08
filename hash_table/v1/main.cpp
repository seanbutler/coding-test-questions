#include <iostream>
#include <vector>
#include <array>

#define MAX_BUCKETS 10

namespace hash
{

    struct Entry
    {
        Entry(int key = 0, std::string value = "")
            : key_(key), value_(value), next_(nullptr)
        {
        }

        int key_;
        std::string value_;
        Entry *next_;
    };

    struct Container
    {
        Container() : buckets_{}
        {
        }

        int hash(int key)
        {
            return key % MAX_BUCKETS;
        }

        void add(Entry *entry)
        {
            int hash_val = hash(entry->key_);

            if (buckets_[hash_val] == nullptr)
            {
                buckets_[hash_val] = entry;
            }
            else
            {
                Entry *itor = buckets_[hash_val];
                while (itor->next_ != nullptr)
                {
                    itor = itor->next_;
                }
                itor->next_ = entry;
            }
        }

        void dump()
        {
            for (int n = 0; n < MAX_BUCKETS; ++n)
            {
                Entry* entry_ptr_itor = buckets_[n];
                while (entry_ptr_itor!=nullptr)
                {
                    std::cout << n << " " << entry_ptr_itor->key_ << " " << entry_ptr_itor->value_ << std::endl;
                    entry_ptr_itor = entry_ptr_itor->next_;
                }

            }
        }

        std::array<Entry *, MAX_BUCKETS> buckets_;
    };
}

int main(int, char **)
{
    std::cout << "hash code test questions!\n";

    hash::Container my_hash_container;

    my_hash_container.add(new hash::Entry(52, "Homer"));
    my_hash_container.add(new hash::Entry(10, "Lisa"));
    my_hash_container.add(new hash::Entry(12, "Bart"));
    my_hash_container.add(new hash::Entry(50, "Marge"));

    my_hash_container.dump();

    return 0;
}
