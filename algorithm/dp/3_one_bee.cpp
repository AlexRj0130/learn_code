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
    long long CountPath(int a, int b)
    {
        if (a == b)
            return 1;
        vector<long long> array(102, 0);
        for (int i = a; i <= b; i++)
        {
            if (i == a)
            {
                array[i] = 1;
                continue;
            }
            array[i] = array[i - 1] + array[i - 2];
        }
        return array[b];
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
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        cout << solution.CountPath(a, b) << endl;
    }
    return 0;
}