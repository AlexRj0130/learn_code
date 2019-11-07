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
    string ReverseSentence(string str) {
        bool flag = true;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return str;

        stack<string> sstr;
        string tmp;
        for (int i = 0; i <= str.size(); i++)
        {
            if (i == str.size())
            {
                if (!tmp.empty())
                    sstr.push(tmp);
                break;
            }
            if (str[i] != ' ')
            {
                tmp += str[i];
            }
            else
            {
                if (!tmp.empty())
                {
                    sstr.push(tmp);
                    tmp = "";
                }
            }
        }

        string ret;
        while (!sstr.empty())
        {
            if (ret.empty())
                ret += sstr.top();
            else
                ret += (" " + sstr.top());
            sstr.pop();
        }
        return ret;
    }
};

int main()
{
    return 0;
}