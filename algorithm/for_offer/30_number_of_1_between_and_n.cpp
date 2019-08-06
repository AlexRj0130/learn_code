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
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = i;
            while(tmp != 0)
            {
                if (tmp % 10  == 1)
                    count++;
                tmp /= 10;
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}