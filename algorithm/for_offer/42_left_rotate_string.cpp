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
    string LeftRotateString(string str, int n) {
        if (str.size() <= 1)
            return str;

        n = n % str.size();
        if (0 == n)
            return str;

        string ret = str.substr(n, str.size()) + str.substr(0, n);
        return ret;
    }
};

int main()
{
    return 0;
}