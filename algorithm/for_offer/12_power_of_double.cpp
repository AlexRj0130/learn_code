#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        
        bool flag = false;
        if (exponent < 0)
        {
            flag = true;
            exponent *= -1;
        }


        long double tmp = base;
        while (exponent > 1)
        {
            tmp = tmp * base;
            exponent--;
        }
        return flag ? 1 / tmp : tmp;
    }
};

int main()
{
    return 0;
}