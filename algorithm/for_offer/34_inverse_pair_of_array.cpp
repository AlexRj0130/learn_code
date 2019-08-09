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

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        long long count = MergeSortCount(data, 0, data.size() - 1);
        return count % 1000000007;
    }

private:
    long long MergeSortCount(vector<int> & data, int sta, int end)
    {
        if (sta >= end)
            return 0;

        int mid = (sta + end) / 2;
        long long lCount = MergeSortCount(data, sta, mid);
        long long rCount = MergeSortCount(data, mid + 1, end);

        long long count = lCount + rCount;

        int lRead = sta;
        int rRead = mid + 1;
        int readTmp = 0;
        vector<int> tmp(end - sta + 1);
        while(lRead <= mid && rRead <= end)
        {
            if (data[lRead] <= data[rRead])
            {
                tmp[readTmp++] = data[lRead++];
            }
            else
            {
                tmp[readTmp++] = data[rRead++];
                count += mid - lRead + 1;  // Here count the InversePairs
            }
        }
        while(lRead <= mid)
        {
            tmp[readTmp++] = data[lRead++];
        }
        while(rRead <= end)
        {
            tmp[readTmp++] = data[rRead++];
        }
        
        for (int i = 0, j = sta; i < tmp.size(); i++, j++)
        {
            data[j] = tmp[i];
        }

        return count;
    }
};

int main()
{
    Solution solution;

    vector<int> array1;
    array1.push_back(3);
    array1.push_back(2);
    array1.push_back(1);
    solution.InversePairs(array1);

    return 0;
}