#include <iostream>
#include <stdlib.h>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5)
            return false;
        
        vector<int> count(14, 0);
        int maxNum = 0;
        int minNum = 15;
        for (int i = 0; i < 5; i++)
        {
            count[numbers[i]]++;
            if (numbers[i] == 0)
                continue;
            if (count[numbers[i]] > 1)
                return false;
            maxNum = maxNum > numbers[i] ? maxNum : numbers[i];
            minNum = minNum < numbers[i] ? minNum : numbers[i];
        }
        return maxNum - minNum <= 4;
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(0);
    numbers.push_back(5);
    numbers.push_back(0);

    Solution solution;
    solution.IsContinuous(numbers);

    return 0;
}