#include <iostream>

struct list
{
    list(int data = 0)
        : data_(data), next_(nullptr)
    {
    }

    int data_;
    list *next_;
};

void insert_after(list *L, list *N)
{
    if (L->next_ == nullptr)
    {
        L->next_ = N;
    }
    else
    {
        N->next_ = L->next_;
        L->next_ = N;
    }
}

void insert_before(list *L, list *N)
{
    insert_after(N, L);
}

void append(list *L, list *N)
{
    while (L->next_ != nullptr)
    {
        L = L->next_;
    }
    L->next_ = N;
}

list *new_node(int D = 0)
{
    return new list(D);
}

void dump(list *L)
{
    while (L != nullptr)
    {
        std::cout << L->data_ << " ";
        L = L->next_;
    }
    std::cout << std::endl;
}

int get(list *L, int pos)
{
    for (int n = 0; n < pos; ++n)
    {
        L = L->next_;
    }

    return L->data_;
}

void set(list *L, int pos, int val)
{
    for (int n = 0; n < pos; ++n)
    {
        L = L->next_;
    }

    L->data_ = val;
}

int length(list *L)
{
    int ctr = 0;

    while (L != nullptr)
    {
        L = L->next_;
        ++ctr;
    }
    return ctr;
}

void reverse(list *L) // WIP
{
    int len = length(L);

    for (int n = 0; n < (len / 2); ++n)
    {
        int tmp;
        tmp = get(L, n);
        set(L, n, get(L, (length(L) - 1) - n));
        set(L, (length(L) - 1) - n, tmp);
    }
}

int main(int, char **)
{
    std::cout << "reverse linked list leet-code-tests!\n";

    list *list0 = new_node(0);

    srand(time(nullptr));

    int m = rand()%32;
    for (int n=1; n<m; ++n)
    {
        append(list0, new_node(n));
    }

    dump(list0);

    reverse(list0);

    dump(list0);

    return 0;
}
