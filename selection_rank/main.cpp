






#include <vector>
#include <iostream>
#include <algorithm>

int partition(std::vector<int> & v, int left, int right, int pivot)
{
    while (true)
    {
        while (left <= right && v[left] <= pivot)
            left++;
        while (left <= right && v[right] > pivot)
            right--;
        
        if (left > right)
            return left - 1;
        
        int t = v[left];
        v[left] = v[right];
        v[right] = t;
    }
}

int SelectionRank(std::vector<int> & v, int left, int right, int rank)
{
    int pivot = v[left + (rand() % (right - left + 1))];
    
    int leftEnd = partition(v, left, right, pivot);
    
    int leftSize = leftEnd - left + 1;
//    std::cout << "pivot: " << pivot << std::endl;
//    std::cout << "leftEnd: " << leftEnd << std::endl;
    std::cout << "rank: " << rank << std::endl;
//    for (int i = 0; i < (int)v.size(); ++i)
//        std::cout << v[i] << " ";
//    std::cout << std::endl;
    if (leftSize == rank)
    {
        std::cout << "RANK" << std::endl;
        int max = -1;
        for (int i = left; i <= leftEnd; ++i)
        {
            if (v[i] > max) max = v[i];
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
        return max;
    }
    else if (rank < leftSize)
    {
        std::cout << "Going left" << std::endl;
        return SelectionRank(v,left,leftEnd,rank);
    }
    else
    {
        std::cout << "Going right" << std::endl;
        return SelectionRank(v, leftEnd + 1, right, rank - leftSize);
    }
}

int main()
{
//    std::vector<int> v =  {1,3,4,2,10,9,7,8,0,5};  //10 elements.
    std::vector<int> v =  {10,9,8,7,6,1,2,3,4,5}; // 10
    srand (time(NULL));
    for (int i = 0; i < (int)v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    int rank = SelectionRank(v, 0, v.size() - 1, 3);
    std::cout << rank << std::endl;
    rank = SelectionRank(v, 0, v.size() - 1, v.size() - 3 + 1);
    std::cout << rank << std::endl;
    return 0;
}