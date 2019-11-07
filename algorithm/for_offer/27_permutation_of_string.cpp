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
        helper(str, tmp, ret);

        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());  // Note: if want to remove duplicate ones, unique first, then erase

        return ret;
    }

private:
    void helper(string str, string tmp, vector<string> & ret)
    {
        if (str.empty() && !tmp.empty())
        {
            ret.push_back(tmp);
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            string localTmp = tmp + str[i];
            string localStr = str;
            localStr = localStr.erase(i, 1);
            helper(localStr, localTmp, ret);
        }
    }
};

int main()
{
    Solution solution;
    string str = "aa";

    vector<string> ret = solution.Permutation(str);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << endl;
    
    return 0;
}