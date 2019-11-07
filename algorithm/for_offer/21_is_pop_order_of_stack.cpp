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
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;

        int count = 0;
        stack<int> stk;
        for (int i = 0; i < pushV.size(); i++)
        {
            stk.push(pushV[i]);
            while(!stk.empty() && stk.top() == popV[count])
            {
                stk.pop();
                count++;
            }
        }

        return count == popV.size();
    }
};  

int main()
{
    return 0;
}