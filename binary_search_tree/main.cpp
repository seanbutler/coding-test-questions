#include <iostream>
#include <list>
#include <vector>

// https://www.hackerrank.com/blog/coding-interview-questions-programmers-should-know/

/*

*/

namespace TreeNode
{

    struct Element
    {
        Element(int V) : val_(V) {}
        int val_;
        Element *left_;
        Element *right_;
    };

    void insert(Element *TN, int V)
    {
        if (TN != nullptr)
        {
            if (V >= TN->val_)
            {
                if (TN->right_ != nullptr)
                    insert(TN->right_, V);
                else
                    TN->right_ = new Element(V);
            }
            else
            {
                if (TN->left_ != nullptr)
                    insert(TN->left_, V);
                else
                    TN->left_ = new Element(V);
            }
        }
        else
        {
            TN = new Element(V);
        }
    }

    void dump(Element *TN, int indent)
    {
        indent++;
        std::cout << TN->val_ << std::endl;

        if (TN->right_ != nullptr)
        {
            for (int n = 0; n < indent; n++)
            {
                std::cout << "   ";
            }
            std::cout << "right ";
            dump(TN->right_, indent);
        }
        if (TN->left_ != nullptr)
        {
            for (int n = 0; n < indent; n++)
            {
                std::cout << "   ";
            }
            std::cout << "left ";
            dump(TN->left_, indent);
        }
    }

}

static const int MAX = 10;

int main(int argc, char **argv)
{
    std::vector<int> randos;

    srand(time(nullptr));
    for (int n = 0; n < MAX; ++n)
    {
        randos.push_back(rand() % MAX);
    }

    for (int R : randos)
    {
        std::cout << R << " ";
    }
    std::cout << std::endl;

    TreeNode::Element *root = new TreeNode::Element(randos[0]);
  
    for (int n=1;n<randos.size(); ++n)
    {
        TreeNode::insert(root, randos[n]);
    }

    int indent = 0;
    TreeNode::dump(root, indent);
}