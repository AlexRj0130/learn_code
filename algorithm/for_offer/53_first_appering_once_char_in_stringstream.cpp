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

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
         vChar.push_back(ch);
    }
    
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if (vChar.empty())
            return '#';

        vector<int> count(256, 0);
        vector<int> pos(256, -1);

        for (int i = 0; i < vChar.size(); i++)
        {
            count[vChar[i]]++;
            if (count[vChar[i]] == 1)
                pos[vChar[i]] = i;
        }

        int minPos = 256;
        char ret;
        for (int i = 0; i < 256; i++)
        {
            if (count[i] == 1)
            {
                if (pos[i] < minPos)
                {
                    minPos = pos[i];
                    ret = (char)i;
                }
            }
        }

        return minPos == 256 ? '#' : ret;
    }

private:
    vector<char> vChar;
};

int main()
{
    return 0;
}