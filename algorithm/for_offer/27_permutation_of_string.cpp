#include <iostream>
#include <stdlib.h>

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
    vector<string> Permutation(string str) {
        vector<string> ret;        
        string tmp;


    }

private:
    void helper(string str, string tmp, vector<string> & ret)
    {
        if (str.empty())
        {
            ret.push_back(tmp);
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            
        }
    }
};

int main()
{
    return 0;
}