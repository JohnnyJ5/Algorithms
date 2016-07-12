


#include <stack>
#include <vector>
#include <string>
#include <iostream>

const std::vector<std::string> keywords = {"a", "aag", "apple", "hair"};

void backtrack(const std::string & text)
{
    std::stack<std::string> s;
    s.push(text);
    
    while (!s.empty())
    {
        std::string str = s.top();
        s.pop();
        std::cout << "str: " << str << std::endl;
        
        if (str == "")
        {
            std::cout << "We have a match!" << std::endl;
            return;
        }
        
        for(auto it = keywords.begin(); it != keywords.end(); ++it)
        {
            if (*it == str.substr(0,it->size()))
            {
                s.push(str.substr(it->size(), str.size()));
            }
        }
    }
    
    std::cout << "No match" << std::endl;
}

void TestCase1()
{
    backtrack("aahair");
}

void TestCase2()
{
    backtrack("pack");
}

void TestCase3()
{
    backtrack("aagpack");
}

int main()
{
    TestCase1();
    TestCase2();
    TestCase3();
    
    
    return 0;
}