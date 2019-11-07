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

void help(const vector<vector<int> > & s, vector<int> & num, unsigned long long & ret, int sta)
{
    if (sta >= num.size())
    {
        int max = 0;
        for (int i = 1; i < num.size(); i++)
        {
            max += s[num[i]][i];
        }
        ret = ret < max ? ret : max;
        return;
    }

    int tmp = num[sta];
    for (int i = sta; i < num.size(); i++)
    {
        int tmp2 = num[i];
        num[i] = tmp;
        num[sta] = tmp2;
        help(s, num, ret, sta + 1);
        num[i] = tmp2;
        num[sta] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > s(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= n; j++)
            s[i][j] = a * (j - 1) + b * (n - j);
    }

    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++)
        num[i] = i;

    unsigned long long ret = 0xffffffffffffffff;
    help(s, num, ret, 1);
    cout << ret << endl;

    return 0;
}