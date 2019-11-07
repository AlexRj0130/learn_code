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
    bool isNumeric(char* string)
    {
        if (string == NULL)
            return false;

        vector<char> left, right;
        bool eFlag = false;

        while ((*string) != '\0')
        {
            if ((*string) == 'e' || (*string) == 'E')
            {
                if (eFlag)
                    return false;
                eFlag = true;
                string++;
                continue;
            }
            if (!eFlag)
            {
                left.push_back(*string);
            }
            else
            {
                right.push_back(*string);
            }
            string++;
        }

        if (eFlag && (right.empty()))
            return false;

        bool pFlag = false;
        for (int i = 0; i < left.size(); i++)
        {
            if (i == 0)
            {
                if (left[i] == '+' || left[i] == '-' || (left[i] >= '0' && left[i] <= '9'))
                    continue;
                return false;
            }
            if (left[i] == '.')
            {
                if (pFlag)
                    return false;
                pFlag = true;
                continue;
            }
            if (left[i] >= '0' && left[i] <= '9')
                continue;
            return false;
        }

        for (int i = 0; i < right.size(); i++)
        {
            if (i == 0)
            {
                if (right[i] == '+' || right[i] == '-' || (right[i] >= '0' && right[i] <= '9'))
                    continue;
                return false;
            }
            if (right[i] >= '0' && right[i] <= '9')
                continue;
            return false;
        }
        
        return true;
    }
};

int main()
{
    return 0;
}