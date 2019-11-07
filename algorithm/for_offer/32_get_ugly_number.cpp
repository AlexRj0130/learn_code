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

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 6)
            return index;
        
        vector<int> array(index, 1);
        int p0 = 0;
        int p1 = 0;
        int p2 = 0;
        for (int i = 1; i < index; i++)
        {
            int t0 = array[p0] * 2;
            int t1 = array[p1] * 3;
            int t2 = array[p2] * 5;
            array[i] = t0 < t1 ? t0 : t1;
            array[i] = array[i] < t2 ? array[i] : t2;

            if (array[i] == t0) p0++;
            if (array[i] == t1) p1++;
            if (array[i] == t2) p2++;
        }
        return array[index - 1];
    }
};

int main()
{
    return 0;
}