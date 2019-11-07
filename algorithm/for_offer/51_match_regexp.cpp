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
    bool match(char* str, char* pattern)
    {
        if (str == NULL || pattern == NULL)
            return false;

        vector<char> vStr;
        while ((*str) != '\0')
        {
            vStr.push_back(*str);
            str++;
        }

        vector<char> vPat;
        while ((*pattern) != '\0')
        {
            vPat.push_back(*pattern);
            pattern++;
        }

        int idxStr = 0, idxPat = 0;
        return help(vStr, vPat, idxStr, idxPat);
    }

    bool help(vector<char> & vStr, vector<char> & vPat, int idxStr, int idxPat)
    {
        if (vStr.size() == idxStr && vPat.size() == idxPat)
            return true;
        if (vStr.size() != idxStr && vPat.size() == idxPat)
            return false;

        if (idxPat + 1 < vPat.size() && vPat[idxPat + 1] == '*')
        {
            if (vStr.size() > idxStr && (vStr[idxStr] == vPat[idxPat] || vPat[idxPat] == '.'))
            {
                return help(vStr, vPat, idxStr, idxPat + 2)
                        || help(vStr, vPat, idxStr + 1, idxPat + 2)
                        || help(vStr, vPat, idxStr + 1, idxPat);
            }
            return help(vStr, vPat, idxStr, idxPat + 2);
        }

        if (vStr.size() > idxStr && (vStr[idxStr] == vPat[idxPat] || vPat[idxPat] == '.'))
            return help(vStr, vPat, idxStr + 1, idxPat + 1);
        return false;
    }
};

int main()
{
    return 0;
}