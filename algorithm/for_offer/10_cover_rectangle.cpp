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
    int rectCover(int number) {
        if (number <= 2)
            return number;
        
        if (record.count(number) != 0)
            return record.at(number);

        int tmp = rectCover(number - 1) + rectCover(number - 2);
        record.insert(pair<int, int>(number, tmp));
        return tmp;
    }

private:
    map<int, int> record;
};

int main()
{
    return 0;
}