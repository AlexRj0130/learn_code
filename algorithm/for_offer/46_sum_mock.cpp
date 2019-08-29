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
    int Sum_Solution(int n) {
        int sum = 0;
        help(n, sum);
        return sum; 
    }

    bool help(int n, int & sum)
    {
        sum += n;
        return n && help(n - 1, sum);
    }

};

int main()
{
    Solution solution;
    cout << solution.Sum_Solution(3) << endl;
    return 0;
}