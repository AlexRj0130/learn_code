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
    int jumpFloor(int number) {
        if (number <= 2)  // Note: here is different with Fibonacci
            return number;

        if (record.count(number) != 0)
            return record.at(number);
        
        int tmp = jumpFloor(number - 1) + jumpFloor(number - 2);
        record.insert(pair<int, int>(number, tmp));
        return tmp;
    }
    map<int, int> record;
};

int main()
{
    return 0;
}