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
    int jumpFloorII(int number) {
        if (number <= 2)
            return number;
        
        int mul = 2;
        while(number > 2)
        {
            mul *= 2;
            number--;
        }

        return mul;
    }
};

int main()
{
    return 0;
}