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
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);

        string ret;
        for (int i = 0; i < numbers.size(); i++)
        {
            ret += int2str(numbers[i]);
        }

        return ret;
    }

private:
    bool static cmp(int a, int b)
    {
        string sA = int2str(a);
        string sB = int2str(b);

        return sA + sB < sB + sA;
    }

    string static int2str(int a)
    {
        stringstream ss;
        ss << a;
        
        string str;
        ss >> str;
        return str;
    }
};

int main()
{
    return 0;
}