#include <iostream>

struct list
{
    list(int data = 0) 
    : data_(data)
    , next_(nullptr)
    {
    }

    int data_;
    list *next_;
};


void insert_after(list *L, list *N) {
    if ( L->next_ == nullptr )
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


list* new_node(int D=0)
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
    for (int n=0;n<pos; ++n)
    {
        L = L->next_;
    }

    return L->data_;
}

void set(list *L, int pos, int val)
{
    for (int n=0;n<pos; ++n)
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
    int len = length(L)-1;


    for (int n=0; n<len/2; ++n) {
        std::cout << n << " "; 
        std::cout << get(L, n) << " ";
        std::cout << get(L, len-n) << std::endl;
    }
}




int main(int, char **)
{
    std::cout << "reverse linked list leet-code-tests!\n";

    list * list0 = new_node(0);

    append(list0, new_node(1));
    append(list0, new_node(2));

    dump(list0);
    std::cout << length(list0) << std::endl;

    append(list0, new_node(3));
    append(list0, new_node(4));

    dump(list0);
    std::cout << length(list0) << std::endl;

    std::cout << get(list0, 0) << std::endl;
    std::cout << get(list0, 4) << std::endl;
    std::cout << get(list0, 3) << std::endl;
    std::cout << get(list0, 1) << std::endl;

    std::cout << length(list0) << std::endl;

    dump(list0);

    reverse(list0);

    dump(list0);
    
    return 0;
}

