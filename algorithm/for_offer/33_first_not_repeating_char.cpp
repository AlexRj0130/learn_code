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
    int FirstNotRepeatingChar(string str) {
        vector<int> arrayCount(128, 0);
        vector<int> arrayPos(128, -1);

        for (int i = 0; i < str.size(); i++)
        {
            arrayCount[str[i]]++;
            arrayPos[str[i]] = arrayPos[str[i]] == -1 ? i : arrayPos[str[i]];
        }

        int minPos = -1;
        for (int i = 0; i < 128; i++)
        {
            if (arrayCount[i] == 1)
            {
                if (minPos == -1)
                    minPos = arrayPos[i];
                else
                    minPos = minPos < arrayPos[i] ? minPos : arrayPos[i];
            }
        }
        return minPos;
    }
};

int main()
{
    return 0;
}