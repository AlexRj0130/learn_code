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

void help()
{
    int m, i, n;
    cin >> m >> i >> n;
    vector<vector<int> > input(m, vector<int>(m, 0));
    vector<vector<int> > degree(n, vector<int>());
    int k;
    cin >> k;
    for (int z = 0; z < k; z++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        input[x][y] = w;
        input[y][x] = w;
        if (x == i)
            degree[0].push_back(y);
        if (y == i)
            degree[0].push_back(x);
    }

    vector<vector<int> > output(m, vector<int>(m, 0));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (y == i)
                continue;
            if 
        }
    }
}

int main()
{
    int group;
    cin >> group;
    for (int i = 0; i < group; i++)
    {
        help();
    }
    return 0;
}