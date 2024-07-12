
#include <cstddef>

#include <iostream>
#include <vector>

bool solution(std::string const &s)
{
    std::vector<char> brackets_stack;

    if (s.size() == 0)
    {
        return true;
    }

    for (size_t char_pos = 0; char_pos < s.size(); ++char_pos)
    {
        if ((s[char_pos] == '[') || (s[char_pos] == '{') || (s[char_pos] == '('))
        {
            brackets_stack.push_back(s[char_pos]);
        }
        else if ((s[char_pos] == ']') || (s[char_pos] == '}') || (s[char_pos] == ')'))
        {
            brackets_stack.pop_back();
        }
        else
        {
            return false;
        }
    }

    if (brackets_stack.size() != 0)
    {
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    std::string result = "";

    std::cout << solution("[]");

    std::cout << solution("({[]})");

    std::cout << solution("");

    std::cout << solution("{[}");

    std::cout << solution("((()[]))");

    std::cout << solution("(brace)");

    std::cout << solution("{[]");


}
