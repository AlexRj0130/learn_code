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

int cmp(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])
        return 1;
    else if (a[2] > b[2])
        return -1;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];

    vector<int> c;
    vector<vector<int> > tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<int> tmptmp;
            tmptmp.push_back(i);
            tmptmp.push_back(j);
            tmptmp.push_back((a[i]*b[j]) % m);
            tmp.push_back(tmptmp);
        }
    }

    sort(tmp.begin(), tmp.end(), cmp);

    map<int, bool> ma;
    map<int, bool> mb;

    for (int i = 0; i < n*n; i++)
    {
        if (ma.count(tmp[i][0]))
            continue;
        if (mb.count(tmp[i][1]))
            continue;
        ma.insert(pair<int, bool>(tmp[i][0], true));
        mb.insert(pair<int, bool>(tmp[i][1], true));
        c.push_back(tmp[i][2]);
    }

    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";

    return 0;
}