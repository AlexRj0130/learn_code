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
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ret;
        if (array.size() < 2)
            return ret;

        int x = array[0];
        int y = array[array.size() - 1];
        int mul = -1;
        
        int i = 0; 
        int j = array.size() - 1;
        while (i < j)
        {
            if (array[i] + array[j] == sum)
            {
                if (mul == -1 || array[i] * array[j] <= mul)
                {
                    x = array[i];
                    y = array[j];
                    mul = x * y;
                }
                j--;
            } else if (array[i] + array[j] < sum)
                i++;
            else 
                j--;
        }

        if (x + y == sum)
        {
            ret.push_back(x);
            ret.push_back(y);
        }
        return ret;
    }
};

int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(4);
    array.push_back(7);
    array.push_back(11);
    array.push_back(15);

    Solution solution;
    solution.FindNumbersWithSum(array, 15);
    return 0;
}