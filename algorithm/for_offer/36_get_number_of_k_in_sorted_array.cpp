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
    int GetNumberOfK(vector<int> data ,int k) {
        int sta = 0;
        int end = data.size() - 1;
        while (sta <= end)
        {
            int mid = (sta + end) / 2;
            if (data[mid] < k)
            {
                sta = mid + 1;
                continue;
            }
            else if (data[mid] > k)
            {
                end = mid - 1;
                continue;   
            }

            int lIndex = mid;
            int rIndex = mid;
            while(lIndex - 1 >= 0 && data[lIndex - 1] == k)
                lIndex--;
            while(rIndex + 1 <= data.size() - 1 && data[rIndex + 1] == k)
                rIndex++;

            return rIndex - lIndex + 1; 
        }

        return 0;
    }
};

int main()
{
    return 0;
}