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
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        int sumTmp = 1;
        int sta = 1;
        for (int i = 2; i < sum;)
        {
            sumTmp += i;
            if (sumTmp == sum)
            {
                vector<int> tmp;
                for (int j = sta; j <= i; j++)
                    tmp.push_back(j);
                ret.push_back(tmp);
                i++;
            }
            else if (sumTmp < sum)
            {
                i++;
            }
            else
            {
                while (sumTmp > sum)
                {
                    sumTmp -= sta;
                    sta++;
                    if (sumTmp == sum)
                    {
                        vector<int> tmp;
                        for (int j = sta; j <= i; j++)
                        tmp.push_back(j);
                        ret.push_back(tmp);
                    }
                }
                i++;
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}