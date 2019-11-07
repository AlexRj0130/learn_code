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
    bool Find(int target, vector<vector<int> > array) {
        int rowLen = array.size();
        int colLen = array[0].size();

        int i = rowLen - 1;
        int j = 0;
        while(i >= 0 && j < colLen)
        {
            if (array[i][j] == target)
                return true;
            if (array[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};

int main()
{
    return 0;
}