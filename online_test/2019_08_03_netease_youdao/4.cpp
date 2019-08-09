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

bool help(int n, int m, vector<vector<int> > squ, int c, int d)
{
    for (int i = 1; i <= n - c; i++)
    {
        for (int j = 1; j <= m -d; j++)
        {
            bool flag = false;
            for (int x = 0; x < c; x++)
            {
                for (int y = 0; y < d; y++)
                {
                    if (squ[i+x][j+y] == 1)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (!flag) return true;
        }
    }

    for (int i = 1; i <= n - d; i++)
    {
        for (int j = 1; j <= m - c; j++)
        {
            bool flag = false;
            for (int x = 0; x < d; x++)
            {
                for (int y = 0; y < c; y++)
                {
                    if (squ[i+x][j+y] == 1)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (!flag) return true;
        }
    } 

    return false;
}

void find()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > squ(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        squ[x][y] = 1;
    }
    int c, d;
    cin >> c >> d;

    if (help(n + 1, m + 1, squ, c, d))
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while(t > 0)
    {
        find();
        t--;
    }
    
    return 0;
}