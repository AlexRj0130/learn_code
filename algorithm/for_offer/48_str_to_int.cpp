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
    int StrToInt(string str) {
        if (str.size() <= 0)
            return 0;
        if (str.size() == 1)
        {
            if (str[0] >= '0' && str[0] <= '9')
                return str[0] - '0';
            return 0;
        }

        int flag = 1;
        int ret = 0;

        if (str[0] >= '0' && str[0] <= '9')
            ret = str[0] - '0';
        else if (str[0] == '+')
            flag = 1;
        else if (str[0] == '-')
            flag = -1;
        else
            return 0;

        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return 0;
            ret += (ret * 10 + str[i] - '0');
        }
        
        return flag * ret;
    }
};

int main()
{
    return 0;
}