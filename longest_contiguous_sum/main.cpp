
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> a = {2,3,-8,-1,2,4,-2,3};
    
    int maxSum = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    for (unsigned int i = 0; i < a.size(); ++i)
    {
        if (sum == 0)
        {
            start = end = i;
        }
        
        sum += a[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            end = i;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }
    
    std::cout << "Max Sum: " << maxSum << std::endl;
    std::cout << "start: " << start << std::endl;
    std::cout << "end: " << end << std::endl;
    
    
    return 0;
}