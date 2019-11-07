#include <iostream>
#include <fstream>
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
    int CountCow(int n)
    {
        int y1 = 1, y2 = 0, y3 = 0, y4 = 0;
        while (--n)
        {
            y1 += y2;
            y2 = y3;
            y3 = y4;
            y4 = y1;
        }
        return y1 + y2 + y3 + y4;
    }
};

int main()
{
    // string path = "D:\\users\\Documents\\code\\learn_code\\debug\\"; // windows format
    // ifstream cin;
    // cin.open(path + "data.dat");
    // if (!cin.is_open())
    // {
    //     cout << "open failed..." << endl;
    //     return 0;
    // }

    Solution solution;
    int n;
    cin >> n;
    while (n)
    {
        cout << solution.CountCow(n) << endl;
        cin >> n;
    }
    return 0;
}