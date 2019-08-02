#include <iostream>
#include <stdlib.h>

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

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        // 如果全是负数，就找一个最大的负数，然后返回
        int maxSum = array[0];
        int sum = 0;
        bool flag = false;
        for (int i = 1; i < array.size(); i++)
        {
            if (array[0] >= 0 || array[i] >= 0)
            {
                flag = true;
            }
            maxSum = maxSum > array[i] ? maxSum : array[i];
        }
        if (!flag)
            return maxSum;
        
        // 否则，通过下面的方法进行计算
        for (int i = 0; i < array.size(); i++)
        {
            sum = sum + array[i] > 0 ? sum + array[i] : 0;
            maxSum = maxSum > sum ? maxSum : sum;
        }

        return maxSum;
    }
};

int main()
{
    return 0;
}