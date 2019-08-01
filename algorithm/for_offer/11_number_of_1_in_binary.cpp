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
    int  NumberOf1(int n) {
        unsigned int number = (unsigned int) n;  // Note: force to convert the datatype of int will not change the data in memory.

        int count = 0;
        int tmp = 64;
        while(tmp > 0)
        {
            if ((number & 1) > 0)
                count++;
            number = number >> 1;
            tmp--;
        }
        return count;
    }
};

int main()
{
    return 0;
}