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
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int tmp = data[0];
        for (int i = 1; i < data.size(); i++)
        {
            tmp = tmp ^ data[i];
        }

        int flag = 1;
        while ((flag & tmp) == 0)
        {
            flag = flag << 1;  // Here is important, don't forget.
        }

        vector<int> left, right;
        for (int i = 0; i < data.size(); i++)
        {
            if ((flag & data[i]) == 0)
                left.push_back(data[i]);
            else
                right.push_back(data[i]);            
        }

        int ret1 = left[0];
        int ret2 = right[0];
        for (int i = 1; i < left.size(); i++)
            ret1 = ret1 ^ left[i];
        for (int i = 1; i < right.size(); i++)
            ret2 = ret2 ^ right[i];
        
        *num1 = ret1;
        *num2 = ret2;
    }
};

int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    data.push_back(4);
    data.push_back(3);
    data.push_back(2);
    data.push_back(1);
    int num1, num2;
    
    Solution solution;
    solution.FindNumsAppearOnce(data, &num1, &num2);
    return 0;
}